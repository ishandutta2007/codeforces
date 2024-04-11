#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn],sum[maxn];
string s;
int main(){
	scanf("%d%d",&n,&m),cin>>s;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+s[i-1]-96;
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),printf("%d\n",sum[y]-sum[x-1]);
	return 0;
}