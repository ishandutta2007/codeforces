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
void solve(){
	int a,b,c,ans=1<<30;
	int aa,ab,ac;
	scanf("%d%d%d",&a,&b,&c);
	For(va,1,30000) For(vb,1,30000/va){
		int vc=c/va/vb;
		int val=abs(a-va)+abs(b-va*vb)+abs(c-va*vb*vc);
		if (val<ans&&vc) ans=val,aa=va,ab=vb,ac=vc;
		++vc;
		val=abs(a-va)+abs(b-va*vb)+abs(c-va*vb*vc);
		if (val<ans&&vc) ans=val,aa=va,ab=vb,ac=vc;
	}
	printf("%d\n%d %d %d\n",ans,aa,aa*ab,aa*ab*ac);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}