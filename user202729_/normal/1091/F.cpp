#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int nsegment;std::cin>>nsegment;

	std::vector<int64_t> len(nsegment);
	for(auto& x:len)std::cin>>x;

	std::string terrain;terrain.reserve(nsegment);
	std::cin>>terrain;

	struct segment{
		int64_t starte,startt;
		int inct;
		// (starte+x, >= startt+inct*x)
	};
	std::vector<segment> segs{{0,0,5}};

	for(int i=0;i<nsegment;++i){
		auto l=len[i];
		char t=terrain[i];

		for(auto& s:segs){
			s.starte-=l;
			s.startt+=l;
		}

		if(t!='L'){
			int64_t de=2*l;
			int factor=t=='W'?1:2;
			int64_t dt=factor*de;

			if(factor<segs.back().inct){
				unsigned i=0;
				while(factor>=segs[i].inct)
					++i;
				// now factor<segs[i].inct and factor>segs[i-1].inct
				segs.insert(segs.begin()+i,{segs[i].starte,segs[i].startt,factor});
				for(auto j=i+1;j<segs.size();++j){
					segs[j].starte+=de;
					segs[j].startt+=dt;
				}

				if(i!=0&&segs[i].inct==segs[i-1].inct)
					segs.erase(segs.begin()+i);
			}

			int tailfactor=t=='W'?3:5;
			while(segs.size()>1&&segs.end()[-2].inct>=tailfactor)
				segs.pop_back();
			segs.back().inct=std::min(segs.back().inct,tailfactor);
		}

		while(segs.size()>1&&segs[1].starte<=0)
			segs.erase(segs.begin());
		if(segs[0].starte<0){
			segs[0].startt+=segs[0].inct*-segs[0].starte;
			segs[0].starte=0;
		}

//		for(auto& s:segs){
//			std::cout<<s.starte<<' '<<s.startt<<' '<<s.inct<<'\n';
//		}
//		std::cout<<"======\n";
	}

	std::cout<<segs[0].startt<<'\n';
}