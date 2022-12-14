#include<iostream>
#include<vector>
#include<algorithm>

int const MOD=998244353;

std::vector<int> process(std::vector<char> v){
	// out[i] = number of ways to put i len=2 blocks on all-0 parts
	unsigned i=1;
	while(i<v.size()&&v[i])
		++i;

	std::vector<int> pre;pre.reserve(v.size()/2+1);pre.push_back(1); // answer for part before i-1
	std::vector<int> ans;ans.reserve(v.size()/2+1);ans.push_back(1); // answer for part before i

	while(true){
		if(i==v.size())
			return ans;

		if(v[i]||v[i-1]){ // blocked
			pre=ans;
			++i;
		}else{
			// new[i] = ans[i] + pre[i-1]
			pre.insert(begin(pre),0);
			if(pre.size()<ans.size())
				pre.resize(ans.size());
			std::transform(begin(pre),begin(pre)+ans.size(),begin(ans),begin(pre),[](int a,int b){
					return a+b-(a+b>=MOD ? MOD : 0);
					});
			std::swap(pre,ans);
			++i;
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int h,w,n;std::cin>>h>>w>>n;
	std::vector<char> hmark(h),wmark(w);
	for(int _=n;_--;){
		for(int z=2;z--;){
			int x,y;std::cin>>x>>y;
			--x;--y;
			hmark[x]=wmark[y]=1;
		}
	}

	int const h_=std::count(begin(hmark),end(hmark),0);
	int const w_=std::count(begin(wmark),end(wmark),0);
	/*
	if(h_==0||w_==0){
		std::cout<<"1\n";
		return 0;
	}
	*/

	std::vector<int> fac(std::max(h,w)+1);
	fac[0]=1;
	for(unsigned i=1;i<fac.size();++i)
		fac[i]=(int64_t)i*fac[i-1]%MOD;

	std::vector<int> invf(std::max(h,w)+1);
	invf[1]=1;
	for(unsigned i=2;i<invf.size();++i)
		invf[i]=MOD-int64_t(MOD/i)*invf[MOD%i]%MOD; // now invf array is inv

	invf[0]=1;
	for(unsigned i=2;i<invf.size();++i)
		invf[i]=invf[i]*(int64_t)invf[i-1]%MOD;

	auto const hp=process(hmark);
	auto const wp=process(wmark);
	int ans=0;
	for(unsigned a=0;a<hp.size();++a) // number of 2x1 blocks
	for(unsigned b=0;b<wp.size();++b){ // number of 1x2 blocks
		if(int(w_-2*b-a) >= 0 && int(h_-2*a-b) >= 0){
			ans=(ans+ (int64_t)wp[b] * fac[w_-2*b]%MOD*invf[w_-2*b-a]%MOD * hp[a]%MOD * fac[h_-2*a]%MOD*invf[h_-2*a-b] )%MOD;
		}
	}
	std::cout<<ans<<'\n';
}