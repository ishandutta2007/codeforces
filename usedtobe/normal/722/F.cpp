#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define re(i,a,b) for (int i=a;i<b;++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
vector<pair<pii,pii> > V;
vector<pii> F;
const int N=111111;
int n,m,md[44],cnt[44];
vector<int> p[44];
void add(pii x){
	re(i,0,p[x.se].size()){
		int X=p[x.se][i];
		++cnt[X];
		md[X]=x.fi%X;
	}
}
void dec(pii x){
	re(i,0,p[x.se].size()){
		int X=p[x.se][i];
		--cnt[X];
	}
}
bool ok(pii x){
	re(i,0,p[x.se].size()){
		int X=p[x.se][i];
		if(cnt[X]&&x.fi%X!=md[X])return 0;
	}
	return 1;
}
int ans[N];
int main() {
	rep(i,1,40)
		for(int j=i;j<=40;j+=i)p[j].pb(i);
	read(n,m);
	rep(i,1,n){
		int k;read(k);
		rep(j,1,k){
			int t;
			read(t);
			V.pb(mp(mp(t,i),mp(j,k)));
		}
	}
	sort(V.begin(),V.end());
	int res;
	re(i,0,V.size()){
		F.pb(V[i].se);
		if(i==(int)V.size()-1||V[i].fi.fi!=V[i+1].fi.fi||V[i].fi.se!=V[i+1].fi.se-1){
			rep(_,1,40)cnt[_]=0;
			res=0;
			int l=0,r=0;
			while(l<F.size()&&r<F.size()){
				while(r<F.size()&&ok(F[r])){
					add(F[r]);
					res=max(res,r-l+1);
					++r;
				}
				while(r<F.size()&&l<F.size()&&!ok(F[r])){
					dec(F[l]);
					++l;
				}
            }
            ans[V[i].fi.fi]=max(res,ans[V[i].fi.fi]);
			while(F.size())F.pop_back();
		}
	}
	rep(i,1,m)printf("%d\n",ans[i]);
	return 0;
}