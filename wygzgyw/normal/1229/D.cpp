// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
int n,k;
int nxt[120];
map<vector<int>,int> M;
int tot,trans[120][120],a[maxn];
vector<int> P[120];
pair<int,int> d[130];
ll ans;
bool vis[130],vis2[130];
vector<int> T;
int hd,tl,q[130],now;
void insert(int x) {
	if (vis[x]) return;
	memset(vis2,0,sizeof(vis2));
	vis2[0]=1; q[hd=tl=1]=0;
	T.push_back(x);
	while (hd<=tl) {
		x=q[hd]; hd++;
		if (tl==120) break;
		for (int &y : T) {
			int z=trans[x][y];
			if (!vis2[z]) vis2[z]=1,q[++tl]=z;
		}
	}
	now=tl;
	memcpy(vis,vis2,sizeof(vis2));
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	vector<int> p(k);
	for (int i=1;i<=k;i++) p[i-1]=i;
	do {
		P[tot]=p,M[p]=tot;
		tot++;
	} while (next_permutation(p.begin(),p.end()));
	for (int i=0;i<tot;i++) for (int j=0;j<tot;j++) {
		for (int l=0;l<k;l++) p[l]=P[j][P[i][l]-1];
		trans[i][j]=M[p];
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<k;j++) read(p[j]);
		a[i]=M[p];
	}
	for (int i=n;i>=1;i--) {
		nxt[a[i]]=i; tot=0;
		for (int j=0;j<120;j++) if (nxt[j]) d[++tot]=MP(nxt[j],j);
		sort(d+1,d+tot+1);
		d[tot+1].first=n+1;
		now=1; T.clear();
		memset(vis,0,sizeof(vis)); vis[0]=1;
		for (int j=1;j<=tot;j++) {
			insert(d[j].second);
			//printf("? %d %d %d %d\n",i,d[j].first,d[j+1].first-1,now);
			ans+=(ll)now*(d[j+1].first-d[j].first);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/