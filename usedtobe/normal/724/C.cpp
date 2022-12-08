#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111;
set<pii> S,T;
set<pii>::iterator it;
int x[N],y[N],n,m,k;
ll ans[N],tmp;
ll nx,ny,dx=1,dy=1;
void change(ll &dx,ll &dy){
	if((dx==-1&&nx==0)||(dx==1&&nx==n))dx=-dx;
	if((dy==-1&&ny==0)||(dy==1&&ny==m))dy=-dy;
}
int main(){
	read(n,m,k);
	rep(i,1,k)read(x[i],y[i]),S.insert(mp(x[i]+y[i],i)),T.insert(mp(x[i]-y[i],i));
	rep(i,1,k)ans[i]=-1;
	rep(_,1,(n+m)*2){
		ll now=1e16;
		now=min(now,(dx==1?n-nx:nx));
		now=min(now,(dy==1?m-ny:ny));
		if(dx!=dy){
			int tot=nx+ny;
			it=S.lower_bound(mp(tot,0));
			while(it!=S.end()&&it->X==tot){
				int p=it->Y;
				ans[p]=(x[p]-nx)/dx+tmp;
				T.erase(mp(x[p]-y[p],p));
				S.erase(it);
				it=S.lower_bound(mp(tot,0));
			}
		}else {
			int tot=nx-ny;
			it=T.lower_bound(mp(tot,0));
			while(it!=T.end()&&it->X==tot){
				int p=it->Y;
				ans[p]=(x[p]-nx)/dx+tmp;
				S.erase(mp(x[p]+y[p],p));
				T.erase(it);
				it=T.lower_bound(mp(tot,0));
			}
		}
		nx+=dx*now;ny+=dy*now;
		tmp+=now;
		change(dx,dy);
	}
	rep(i,1,k)printf("%I64d\n",ans[i]);
	return 0;
}