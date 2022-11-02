#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define int long long
const int N=100005;
int T,x,y;
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&x,&y);
		if (x%y!=0)printf("%lld\n",x);
		else {
			int ans=0,t=y;
			for (int i=2;i*i<=y;i++)if (y%i==0){
				while (y%i==0)y/=i;
				int a=x;
				while (a%t==0)a/=i;
				ans=max(ans,a);
			}
			if (y!=1){
				int a=x;
				while (a%t==0)a/=y;
				ans=max(ans,a);
			}
			printf("%lld\n",ans);
		}
	}
}