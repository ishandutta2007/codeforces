#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> apos(n);
	for(int i=0;i<n;++i){
		int x;std::cin>>x;--x;
		apos[x]=i;
	}

	std::vector<int> b(n);
	for(int& x:b){std::cin>>x;--x;}
	int minprev=n+1;
	int ans=0;
	for(int i=n;i--;){
		int x=apos[b[i]];
		minprev=std::min(minprev,x);
		if(minprev!=x)
			++ans;
	}
	std::cout<<ans<<'\n';
}