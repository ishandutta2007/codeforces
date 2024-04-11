#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,x;std::cin>>n>>x;

	std::vector<int> a(n);for(int& y:a)std::cin>>y;

	if(std::is_sorted(begin(a),end(a))){
		std::cout<<x*(x+1LL)/2<<'\n';
		return 0;
	}

	std::vector<int> i(n);
	for(int j=0;j<n;++j)i[j]=j;
	std::stable_sort(begin(i),end(i),[&](int p,int q){return a[p]<a[q];});

	int l=n-1;
	while(i[l-1]<i[l])--l;

	int64_t ans=0;
	for(int f=0;f<n;++f){
		// consider removing range [f..l[ in i (or extend more to the right)
		if(f){
			if(f>1 and i[f-2]>i[f-1])
				break;
			if(a[i[f]]==a[i[f-1]])
				continue;
			while(l<n and i[f-1]>i[l])
				++l;
		}

		int nl=a[i[f]];
		if(f)nl-=a[i[f-1]];
		ans+=nl*(x-a[i[l-1]]+1LL);
	}

	std::cout<<ans<<'\n';
}