#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	struct Friend{
		int time,amt,cost;
	};
	std::vector<Friend> frs;

	while(ntest--){
		int n,n_min,c0,c;
		std::cin>>n>>n_min>>c>>c0;
		frs.reserve(n+1);
		frs.resize(n);
		for(Friend& f:frs)
			std::cin>>f.time>>f.amt>>f.cost;
		frs.push_back({n_min,-1,-1});

		std::sort(begin(frs),end(frs),[](Friend a,Friend b){
				return a.time<b.time;
				});

		int lasttime=0;
		std::map<int,int> m; // cost (slope) => amt
		m.insert({0,c0});
		int mlen=c0;
		int64_t v0=0; // value of f(0)

		for(Friend f:frs){
			for(int dtime=f.time-lasttime;dtime!=0;){
				auto iter=begin(m);
				if(iter==end(m)){
					std::cout<<"-1\n";
					goto nexttest;
				}
				if(dtime<=iter->second){
					v0+=iter->first*(int64_t)dtime;
					iter->second-=dtime;
					mlen-=dtime;

					if(iter->second==0&&m.size()>=2)
						m.erase(iter);
					break;
				}else{
					v0+=iter->first*(int64_t)iter->second;
					dtime-=iter->second;
					mlen-=iter->second;
					m.erase(iter);
				}
			}
			lasttime=f.time;

			if(f.amt==-1){ // placeholder
				break; // it's ok for mlen to be > c
			}

			m[f.cost]+=f.amt;
			mlen+=f.amt;

			while(mlen>c){
				// auto iter=rbegin(m);
				auto iter=--end(m);
				if(mlen-c<=iter->second){
					iter->second-=mlen-c;
					mlen=c;

					if(iter->second==0&&m.size()>=2)
						m.erase(iter);
					break;
				}else{
					mlen-=iter->second;
					m.erase(iter);
				}
			}
		}

		if(m.empty())
			std::cout<<"-1\n";
		else
			std::cout<<v0<<'\n';

nexttest:;
	}
}