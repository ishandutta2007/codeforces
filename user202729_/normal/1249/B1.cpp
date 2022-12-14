#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	std::vector<int> a,ans;
	std::vector<char> vis;

	while(ntest--){
		int n;std::cin>>n;
		a.resize(n);
		for(int& x:a){std::cin>>x;--x; }

		vis.assign(n,false);
		ans.resize(n);
		for(int i=0;i<n;++i)if(!vis[i]){
			int x=i;
			int cyclelen=0;
			do{
				x=a[x];
				vis[x]=true;
				++cyclelen;
			}while(x!=i);
			do{
				x=a[x];
				ans[x]=cyclelen;
			}while(x!=i);

		}
		for(int x:ans)std::cout<<x<<' ';
		std::cout<<'\n';
	}
}