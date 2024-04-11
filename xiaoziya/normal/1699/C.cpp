#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,mod=1000000007;
int n,T,ans;
int a[maxn],p[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),p[a[i]]=i;
		int l=p[0],r=p[0];
		for(int i=0;i<n;i++){
			if(l<=p[i]&&p[i]<=r)
				ans=1ll*ans*(r-l+1-i)%mod;
			l=min(l,p[i]),r=max(r,p[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}