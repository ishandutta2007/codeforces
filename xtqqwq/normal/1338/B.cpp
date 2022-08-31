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

int n,tot,now,cnt,fl;
int v[200005],nxt[200005],h[100005],du[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
	du[x]++,du[y]++;
}

bool dfs(int u,int fa){
//	cout<<"dfs "<<u<<' '<<now<<endl;
	if(!nxt[h[u]]&&now>=0&&now%2==1) fl=1;
	if(!nxt[h[u]]) now=0;
	int tcnt=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(now>=0) now++;
		if(dfs(v[p],u)) tcnt++;
		if(now>=0) now++;
	}
	if(tcnt>1) cnt-=tcnt-1;
	return !nxt[h[u]];
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	int rt=0;
	for(int i=1;i<=n;i++) if(du[i]>1) rt=i;
	now=-1,cnt=n-1;
	dfs(rt,-1);
	printf("%d %d\n",2*fl+1,cnt);
	return 0;
}