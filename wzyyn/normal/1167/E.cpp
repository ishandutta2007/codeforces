#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
ll ans;
int n,x,i,a[N],f[N],j,las;
vector<int>v[N];
int main(){
	scanf("%d%d",&n,&x);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
	f[x+1]=1e9;
	for (i=x;i;i--)
		if (v[i].size()){
			if (v[i][v[i].size()-1]<f[i+1]) f[i]=v[i][0];
			else f[i]=-1;
		}else f[i]=f[i+1];
	for (i=j=0;i<x;i++){
		if (v[i].size()){
			if (v[i][0]<las) break;
			las=v[i][v[i].size()-1];
		}
		j=max(j,i+2);
		for (;j<=x && f[j]<las;j++);
		ans+=x-j+2;
	}
	printf("%lld",ans);
}