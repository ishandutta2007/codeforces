#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m,k,p,h[MAXN+5],a[MAXN+5];
int cnt[MAXN+5];
bool check(ll x){
	memset(cnt,0,sizeof(cnt));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=1;i<=n;i++) if(h[i]+1ll*a[i]*m>x) q.push(mp(x/a[i],i));
	if(!q.empty()&&q.top().fi==0) return 0;
	for(int i=1;i<=m&&!q.empty();i++){
		for(int j=1;j<=k&&!q.empty();j++){
			pair<ll,int> pp=q.top();q.pop();
			int id=pp.se;cnt[id]++;
			if(h[id]+1ll*a[id]*m>x+1ll*p*cnt[id])
				q.push(mp((x+1ll*p*cnt[id])/a[id],id));
		}
		if(!q.empty()&&q.top().fi<=i) return 0;
	} return q.empty();
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++) scanf("%d%d",&h[i],&a[i]);
	ll l=0,r=1e18,x=0,mid;
	while(l<=r) check(mid=l+r>>1)?x=mid,r=mid-1:l=mid+1;
	printf("%lld\n",x);
	return 0;
}