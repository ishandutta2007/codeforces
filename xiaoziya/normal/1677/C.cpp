#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
long long ans;
int ca[maxn],cb[maxn],ac[maxn],bc[maxn],vis[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&ca[i]),ac[ca[i]]=i;
		for(int i=1;i<=n;i++)
			scanf("%d",&cb[i]),bc[cb[i]]=i;
		int L=1,R=n;
		for(int i=1;i<=n;i++)
			if(vis[i]==0){
				int tot=0;
				for(int j=i;vis[j]==0;j=ac[cb[j]])
					vis[j]=1,tot++;
				for(int j=1;j<=tot/2;j++)
					ans+=R+R,ans-=L+L,L++,R--;
			}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			vis[i]=0;
	}
	return 0;
}