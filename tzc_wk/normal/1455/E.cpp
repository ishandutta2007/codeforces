#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const ll INF=1e10;
int x[5],y[5],p[5];
void solve(){
	ll ans=INF;
	for(int i=1;i<=4;i++) scanf("%d%d",&x[i],&y[i]),p[i]=i;
	do {
		int x1,x2,x3,x4;x1=x[p[1]],x2=x[p[2]],x3=x[p[3]],x4=x[p[4]];
		int y1,y2,y3,y4;y1=y[p[1]],y2=y[p[2]],y3=y[p[3]],y4=y[p[4]];
		vector<int> v;
		if(x2>=x1) v.pb(x2-x1);if(x2>=x3) v.pb(x2-x3);
		if(x4>=x1) v.pb(x4-x1);if(x4>=x3) v.pb(x4-x3);
		if(y3>=y1) v.pb(y3-y1);if(y3>=y2) v.pb(y3-y2);
		if(y4>=y1) v.pb(y4-y1);if(y4>=y2) v.pb(y4-y2);
		for(int i=0;i<v.size();i++){
			vector<int> vx,vy;
			vx.pb(x1);vx.pb(x2-v[i]);vx.pb(x3);vx.pb(x4-v[i]);
			vy.pb(y1);vy.pb(y2);vy.pb(y3-v[i]);vy.pb(y4-v[i]);
			sort(vx.begin(),vx.end());sort(vy.begin(),vy.end());
			ll sum=0;
			for(int j=0;j<4;j++) sum+=abs(vx[j]-vx[1]);
			for(int j=0;j<4;j++) sum+=abs(vy[j]-vy[1]);
			chkmin(ans,sum);
		}
	} while(next_permutation(p+1,p+5));
	printf("%lld\n",ans);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}
/*
1
0 3
4 4
4 5
10 3
*/