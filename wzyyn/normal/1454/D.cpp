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
const int N=200005;
ll q1[25],q2[25],n;
void solve(){
	*q1=0;
	scanf("%lld",&n);
	memset(q1,0,sizeof(q1));
	memset(q2,0,sizeof(q2));
	for (int i=2;1ll*i*i<=n;i++)
		if (n%i==0){
			q1[++*q1]=i;
			for (;n%i==0;n/=i,++q2[*q1]);
		}
	if (n!=1)
		q1[++*q1]=n,q2[*q1]=1;
	ll mx=0;
	For(i,1,*q1) mx=max(mx,q2[i]);
	printf("%lld\n",mx);
	For(i,1,mx){
		ll ans=1;
		For(j,1,*q1)
			if (q2[j]>=mx-i+1)
				ans*=q1[j];
		printf("%lld ",ans);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}