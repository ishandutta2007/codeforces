#include<iostream>
#include<vector>
#include<algorithm>

struct ST{
	std::vector<int> d;
	ST(std::vector<int> const& a):d(2*a.size()){
		std::copy(begin(a),end(a),begin(d)+a.size());
		for(auto i=a.size();--i;)
			d[i]=std::min(d[i<<1],d[i<<1|1]);
	}

	size_t nextle(size_t i,int const val)const{ // cyclic
		i+=d.size()/2;
		while(d[i]>val)
			if(i&1){
				++i;
				if(i==d.size())
					i=d.size()/2;
			}else
				i>>=1;
		while(i<d.size()/2)
			if(d[i<<1]<=val)
				i<<=1;
			else
				i=i<<1|1;
		return i-d.size()/2;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;
	auto minmax=std::minmax_element(begin(a),end(a));
	int const mina=*(minmax.first);
	int const maxa=*(minmax.second);

	if(mina>(maxa-1)/2){
		while(n--)std::cout<<"-1 ";
		std::cout<<'\n';
		return 0;
	}
	
	std::vector<int> ans(n);
	{
		int i=0,ans0=1,max=a[0];
		while(true){
			++i;if(i==n)i=0;
			if(a[i]<=(max-1)/2)
				break;
			else{
				max=std::max(max,a[i]);
				++ans0;
			}
		}

		ans[0]=ans0;
	}

	ST st(a);

	for(int i=n-1;i!=0;--i){
		int nxtans=ans[(i+1)%n];
		int ansi=nxtans+1;
		int stop_thres=(a[i]-1)/2; // stop if <= this
		if(mina<=stop_thres)
			ansi=std::min(ansi,int(st.nextle(i,stop_thres)+n-i)%n);

		ans[i]=ansi;
	}

	for(int x:ans)std::cout<<x<<' ';
	std::cout<<'\n';
}