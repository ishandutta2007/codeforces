#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int main(){
	cin>>k,n=1<<k;
	vector<vector<ll>>a(n,vector<ll>(n));
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%lld",&a[i][j]);
	cin>>m;
	vector<pair<int,int>>V;
	for(int i=1,k1,k2;i<=m;++i)cin>>k1>>k2,V.push_back({k1,k2});
	auto key=V[0];
	for(auto&k1:V)k1.first-=key.first,k1.second-=key.second;
	for(int kk=0;kk<k;++kk){
		vector<vector<ll>>b(n,vector<ll>(n));
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)for(auto k1:V)b[i][j]^=a[(i+n-k1.first)%n][(j+n-k1.second)%n];
		a=b;
		for(auto&k1:V)k1.first=k1.first*2%n,k1.second=k1.second*2%n;
	}
	int k1=0;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(a[i][j])++k1;
	cout<<k1<<endl;
	return 0;
}