#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n,m;
int s;
long long ans=0;
long long maxprofit=0;
cin >> n >> m;
std::vector<int> a;
for(int i=0; i<m; i++){
	int x;
	cin>>x;
	a.push_back(x);
}
std::vector<std::vector<int>> nb(n+1);
for(int i=0; i<m-1; i++) if(a[i]!=a[i+1])
{
	nb[a[i]].push_back(a[i+1]);
	nb[a[i+1]].push_back(a[i]);
	ans+=abs(a[i]-a[i+1]);
}
for(int i=1; i<=n; i++){
	if(nb[i].size()>0){
		std::sort(nb[i].begin(), nb[i].end());
		long long sum=0;
		long long profit =0;
		int l=nb[i].size();
		int mid=nb[i][l/2];
		for(int j=0; j<l; j++){
			sum+=abs(i-nb[i][j]);
			profit+=abs(mid-nb[i][j]);
		}
		if((sum-profit)>maxprofit) maxprofit=sum-profit;
	}
}

cout<<ans-maxprofit;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}