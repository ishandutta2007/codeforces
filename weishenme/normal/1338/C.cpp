#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> Map;
int tot,v[100],tot2,ans[100],T,n;
int solve(int x,int y){
	if (y==-1)return 0;
	int tt=x>>(y<<1);
	int s=0;
	if (tt==0)s=0;
	if (tt==1)s=2ll<<(y<<1);
	if (tt==2)s=3ll<<(y<<1);
	if (tt==3)s=1ll<<(y<<1);
	return solve(x&((1ll<<(y<<1))-1),y-1)+s;
}
signed main(){
	for (int i=1;i<=31;i++)
		if (!Map[i]){
			for (int j=i+1;j;j++)
				if (!Map[j]&&!Map[i^j]){
					Map[j]=Map[i^j]=Map[i]=1;
					ans[++tot]=i;ans[++tot]=j;ans[++tot]=i^j;
					if (i>7)v[tot2++]=j-32;
					break;
				}
		}
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		if (n<=tot){
			printf("%lld\n",ans[n]);
			continue;
		}
		int t1=(n-1)/3+1,t2=n%3;
		for (int i=0;;i+=2)
			if (t1<=(1ll<<i)){
				int x1=(1ll<<i)+t1-1,x2=(1ll<<i<<1)+solve(t1-1,(i>>1)-1),x3=x1^x2;
				if (t2==1)printf("%lld\n",x1);
				if (t2==2)printf("%lld\n",x2);
				if (t2==0)printf("%lld\n",x3);
				break;
			}
			else t1-=1ll<<i;
	}
}