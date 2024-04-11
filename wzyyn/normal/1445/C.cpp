#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=0,rem=y;
		for (int i=2;i*i<=rem;i++) if (rem%i==0){
			ll v1=x,v2=y,t1=0,t2=0;
			for (;v1%i==0;v1/=i,++t1);
			for (;v2%i==0;v2/=i,++t2);
			v1=x;
			for (;t1>=t2;v1/=i,--t1);
			ans=max(ans,v1);
			for (;rem%i==0;rem/=i);
		}
		if (rem!=1){
			ll i=rem;
			ll v1=x,v2=y,t1=0,t2=0;
			for (;v1%i==0;v1/=i,++t1);
			for (;v2%i==0;v2/=i,++t2);
			v1=x;
			for (;t1>=t2;v1/=i,--t1);
			ans=max(ans,v1);
			for (;rem%i==0;rem/=i);
		}
		cout<<ans<<endl;
	}
}