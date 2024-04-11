/*
Date: 2014/11/24 14:51:45 Monday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x3fffffff;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************
#define in 0
#define out 1
const int N=111111,M=111111;
int l,m,n,C,c[2][2],fl=1;
ll t;
struct zcc{int x,y,id;ll t,ans;}a[N];
inline bool cmp(const zcc &a,const zcc &b){return a.t<b.t;}
inline bool cmpx(const zcc &a,const zcc &b){return a.id<b.id;}
multiset<pii>Si,So;
void add(int x,int y){
	if(x==in){Si.insert(mp(a[y].y,y));c[in][a[y].y>fl?1:0]++;}
	else{So.insert(mp(a[y].x,y));c[out][a[y].x>fl?1:0]++;}
}
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF257E.in","r",stdin);freopen("CF257E.out","w",stdout);
#endif
	scanf("%d%*d",&n);rep(i,1,n)scanf("%I64d%d%d",&a[i].t,&a[i].x,&a[i].y),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	Si.insert(mp(-inf,0));Si.insert(mp(inf,0));
	So.insert(mp(-inf,0));So.insert(mp(inf,0));
	a[n+1].t=(1ll<<60);
	int pt=1;
	while(1){
#ifdef LOCAL
		printf("%d %d\n",t,fl);
		ALL(it,Si)printf("(%d,%d)\n",it->x,it->y);
		puts("");
		ALL(it,So)printf("[%d,%d]\n",it->x,it->y);
		puts("");puts("");
#endif
		ll tmp=0;
		if(c[in][0]+c[out][0]>c[in][1]+c[out][1])tmp=fl-max((--Si.lower_bound(mp(fl,0)))->x,(--So.lower_bound(mp(fl,0)))->x);
		else tmp=min((Si.lower_bound(mp(fl,inf)))->x,(So.lower_bound(mp(fl,inf)))->x)-fl;
		if(Si.size()==2&&So.size()==2){
			if(pt>n)break;if(a[pt].x==fl)add(in,pt);else add(out,pt);
			t=a[pt].t;++pt;continue;
		}
		if(tmp+t>a[pt].t){
			if(c[in][0]+c[out][0]>c[in][1]+c[out][1])fl-=a[pt].t-t;
			else fl+=a[pt].t-t;
			if(a[pt].x==fl)add(in,pt);else add(out,pt);
			t=a[pt].t;++pt;
		}else{
			t+=tmp;multiset<pii>::iterator it;
			if(c[in][0]+c[out][0]>c[in][1]+c[out][1]){
				fl-=tmp;
				for(multiset<pii>::iterator it=Si.lower_bound(mp(fl,0));it->x==fl;++it){
					c[in][0]--;a[it->y].ans=t;
				}
				for(multiset<pii>::iterator it=So.lower_bound(mp(fl,0));it->x==fl;++it){
					c[out][0]--;Si.insert(mp(a[it->y].y,it->y));c[in][a[it->y].y>fl?1:0]++;
				}
				while(it=Si.lower_bound(mp(fl,0)),it->x==fl)Si.erase(it);
				while(it=So.lower_bound(mp(fl,0)),it->x==fl)So.erase(it);
			}else{
				fl+=tmp;
				for(multiset<pii>::iterator it=Si.lower_bound(mp(fl,0));it->x==fl;++it){
					c[in][1]--;a[it->y].ans=t;
				}
				for(multiset<pii>::iterator it=So.lower_bound(mp(fl,0));it->x==fl;++it){
					c[out][1]--;Si.insert(mp(a[it->y].y,it->y));c[in][a[it->y].y>fl?1:0]++;
				}
				while(it=Si.lower_bound(mp(fl,0)),it->x==fl)Si.erase(it);
				while(it=So.lower_bound(mp(fl,0)),it->x==fl)So.erase(it);
			}
		}
	}sort(a+1,a+1+n,cmpx);
	rep(i,1,n)printf("%I64d\n",a[i].ans);
	return 0;
}