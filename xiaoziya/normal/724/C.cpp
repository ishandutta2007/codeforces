#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,base=100000;
int n,m,k;
int k1[maxn],k2[maxn],v1[maxn],v2[maxn];
long long ans1[maxn],ans2[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int x=0,y=0,d=1;
	long long now=0;
	while(1){
		if(d==1){
			int p=x-y+base;
			if(v1[p])
				break;
			v1[p]=1;
			if(x==0||y==0){
				int c=min(n-x,m-y);
				ans1[p]=now-x,k1[p]=1;
				x+=c,y+=c,now+=c;
			}
			else{
				int c=min(x,y);
				ans1[p]=now+x,k1[p]=-1;
				x-=c,y-=c,now+=c;
			}
		}
		else{
			int p=x+y;
			if(v2[p])
				break;
			v2[p]=1;
			if(x==n||y==0){
				int c=min(x,m-y);
				ans2[p]=now+x,k2[p]=-1;
				x-=c,y+=c,now+=c;
			}
			else{
				int c=min(n-x,y);
				ans2[p]=now-x,k2[p]=1;
				x+=c,y-=c,now+=c;
			}
		}
		d^=1;
		if((x==0||x==n)&&(y==0||y==m))
			break;
	}
	for(int i=1,x,y;i<=k;i++){
		scanf("%d%d",&x,&y);
		int u=v1[x-y+base],v=v2[x+y];
		long long au=ans1[x-y+base]+k1[x-y+base]*x;
		long long av=ans2[x+y]+k2[x+y]*x;
		if(u==0&&v==0)
			puts("-1");
		else if(u==0)
			printf("%lld\n",av);
		else if(v==0)
			printf("%lld\n",au);
		else printf("%lld\n",min(au,av));
	}
	return 0;
}