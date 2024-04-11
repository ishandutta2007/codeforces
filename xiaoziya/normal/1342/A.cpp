#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int T,n,m,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		b=min(b,a+a);
		long long ans=0;
		if((n>0)==(m>0)){
			if(n>0){
				int c=min(n,m);
				ans+=1ll*c*b,n-=c,m-=c;
			}
			else{
				int c=max(n,m);
				ans-=1ll*c*b,n-=c,m-=c;
			}
		}
		printf("%lld\n",ans+1ll*(abs(n)+abs(m))*a);
	}
	return 0;
}