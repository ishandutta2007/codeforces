#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[100005],x[100005],y[100005],d[100005],delta1[100005],delta2[100005];
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=m;i++)	cin>>x[i]>>y[i]>>d[i];
	for(int i=1;i<=k;i++){
		int l,r;
		cin>>l>>r;
		delta1[l]++;delta1[r+1]--;
	}
	for(int i=1;i<=m;i++)	delta1[i]+=delta1[i-1];
	for(int i=1;i<=m;i++){
		delta2[x[i]]+=delta1[i]*d[i];
		delta2[y[i]+1]-=delta1[i]*d[i];
	}
	for(int i=1;i<=n;i++)	delta2[i]+=delta2[i-1];
	for(int i=1;i<=n;i++)	cout<<a[i]+delta2[i]<<" ";
	return 0;
}