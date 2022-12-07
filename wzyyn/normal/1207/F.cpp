#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 hfjskghsdjkfg
using namespace std;
const int B=800;
ll ans[B+5][B+5],a[B*B];
int main(){
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			a[x]+=y;
			For(i,1,B) ans[i][x%i]+=y;
		}
		else if (x<=B) printf("%lld\n",ans[x][y]);
		else{
			ll ans=0;
			for (;y<=500000;ans+=a[y],y+=x);
			printf("%lld\n",ans);
		}
	}
}