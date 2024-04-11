#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg,ps,stp;
int a[maxn],c[maxn],p[maxn],mn[maxn],vis[maxn],res[maxn];
string s;
void sieve(int n){
	c[1]=1;
	for(int i=2;i<=n;i++){
		if(c[i]==0)
			p[++ps]=i,mn[i]=i;
		for(int j=1;j<=ps&&i*p[j]<=n;j++){
			c[i*p[j]]=1,mn[i*p[j]]=p[j];
			if(i%p[j]==0)
				break;
		}
	}
}
int main(){
	scanf("%d",&T),sieve(1000);
	while(T--){
		scanf("%d",&n),stp++;
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(vis[mn[a[i]]]!=stp)
				vis[mn[a[i]]]=stp,res[mn[a[i]]]=++ans;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d%c",res[mn[a[i]]],i==n? '\n':' ');
	}
	return 0;
}