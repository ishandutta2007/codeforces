#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=500005;
int n,m,T,stp;
int a[maxn],vis[maxn];
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans+=a[i];
	int lst=0;
	while(m--){
		int t,x,y;
		scanf("%d%d",&t,&x);
		if(t==1){
			scanf("%d",&y);
			if(vis[x]!=stp)
				ans+=y-lst;
			else ans+=y-a[x];
			vis[x]=stp,a[x]=y;
		}
		if(t==2)
			stp++,ans=1ll*x*n,lst=x;
		printf("%lld\n",ans);
	}
	return 0;
}