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
const int B=40000;
pii ans,qq[B+5];
int a,b,p,q;
void solve(){
	ans=pii(1<<30,0);
	scanf("%d%d%d%d",&a,&b,&p,&q);
	if (b-a+1>=B){
		For(i,1,B) qq[i]=pii(1ll*p*(i-1)%q*2,i-1);
		sort(qq+1,qq+B+1);
		int tp=1;
		For(i,2,B)
			if (qq[i].fi!=qq[i-1].fi)
				qq[++tp]=qq[i];
		//For(i,1,B) cout<<
		for (;b-a+1>=B;a+=B){
			int v=1ll*p*a%q*2,val;
			int p=lower_bound(qq+1,qq+tp+1,pii((3ll*q-v)%(2*q),-1))-qq;
			ans=min(ans,pii(abs(q-(1ll*v+qq[(p+tp-1)%tp+1].fi)%(2*q)),a+qq[(p+tp-1)%tp+1].se));
			ans=min(ans,pii(abs(q-(1ll*v+qq[(p+tp-2)%tp+1].fi)%(2*q)),a+qq[(p+tp-2)%tp+1].se));
		}
	}
	for (;a<=b;++a){
		int v=1ll*p*a%q*2;
		ans=min(ans,pii(abs(v-q),a));
	}
	printf("%d\n",ans.se);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}