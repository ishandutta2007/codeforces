#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,n,a[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[i]==a[j])++j;
			if(j>n){
				ans=max(ans,j-i);
				break;
			}
			int x=a[i],y=a[j],cur=j-i+1;
			while(1){
				int z=y*2-x;
				int pos=lower_bound(a+1,a+1+n,z)-a;
				if(pos<=n){
					++cur;
					y=a[pos];
				}else break;
			}
			ans=max(ans,cur);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}