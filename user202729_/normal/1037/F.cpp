#include<iostream>
#include<vector>
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnumber,k;std::cin>>nnumber>>k;
	std::vector<int> a(nnumber);for(int& x:a)std::cin>>x;
	/// Compute number of subarrays with length k+a(k-1) for some a
	/// of an array with length (len).
	auto nsegment=[=](int len){
		if(len<k)return 0ULL;
		// result = max(0,len+1-k)+max(0,len+1-(2k-1))+max(0,len+1-(3k-2))+...
		// = sum (i=0..inf) max(0,len+1-k-(k-1)i)
		int maxi=(len+1-k)/(k-1); // such that len+1-k-(k-1)i >= 0
		// then return sum (i=0..maxi) (len+1-k-(k-1)i)
		return (maxi+1ULL)*(len+1-k)-(k-1)*(maxi*(maxi+1ULL)/2);
	};

	std::vector<int> lastGtOf(nnumber); // lastGtOf[i]=index j nearest to i such that
	// j<i and a[j]>a[i], or -1 if none exists
	std::vector<int> candidates={-1};
	for(int i=0;i<nnumber;++i){
		while(candidates.back()>=0&&a[candidates.back()]<=a[i])
			candidates.pop_back();
		lastGtOf[i]=candidates.back();
		candidates.push_back(i);
	}
	int constexpr mod=1e9+7;
	int ans=0;
	candidates.assign(1,nnumber);
	for(int i=nnumber;i-->0;){
		while(candidates.back()<nnumber&&a[candidates.back()]<a[i])
			candidates.pop_back();
		int lastGt=lastGtOf[i];
		int nextGe=candidates.back();
		ans=((nsegment(nextGe-lastGt-1)-nsegment(nextGe-i-1)-nsegment(i-lastGt-1))%mod
			*a[i]+ans)%mod;
		candidates.push_back(i);
	}
	std::cout<<ans<<'\n';
}