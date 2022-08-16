#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=18;
int n,cnt;
int a[200005],f[200005];
pii d[300005][2],now[200005];

int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}

bool merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return false;
	f[fx]=fy,cnt++;
	return true;
}

void upd(int x,pii t){
	if(t.se==d[x][0].se) chkmax(d[x][0].fi,t.fi);
	else if(!chkmax(d[x][0],t)) chkmax(d[x][1],t);
}

int main(){
	n=readint();
	ll ans=0;
	for(int i=1;i<=n;i++) a[i]=readint(),f[i]=i,ans-=a[i];
	while(1){
		for(int i=0;i<(1<<N);i++) d[i][0]=d[i][1]=mp(0,0);
		for(int i=1;i<=n;i++) upd(a[i],mp(a[i],getf(i)));
		for(int i=0;i<N;i++) for(int j=0;j<(1<<N);j++) if(j&(1<<i)) upd(j,d[j^(1<<i)][0]),upd(j,d[j^(1<<i)][1]);
		for(int i=1;i<=n;i++) now[i]=mp(0,0);
		for(int i=0;i<=n;i++){
			int tmp=a[i]^((1<<N)-1);
			if(d[tmp][0].se==getf(i)) chkmax(now[f[i]],mp(d[tmp][1].fi+a[i],d[tmp][1].se));
			else chkmax(now[f[i]],mp(d[tmp][0].fi+a[i],d[tmp][0].se));
		}
		for(int i=0;i<=n;i++) if(f[i]==i&&merge(i,now[i].se)) ans+=now[i].fi;
		if(cnt==n) break;
	}
	printf("%lld\n",ans);
	return 0;
}