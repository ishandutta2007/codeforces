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
const int maxn=(1e5)+10;
int T,n;
char s[maxn],t[maxn];
vector<int> g[30];
int now[30],p[maxn];
ll ans,ANS;
namespace BIT {
	int tr[maxn];
	void init() { for (int i=1;i<=n;i++) tr[i]=0; }
	void add(int x) { for (;x<=n;x+=x&(-x)) tr[x]++; }
	int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
	int query(int l,int r) { if (l>r) return 0; return query(r)-query(l-1); }
};
int query(int x,int y,int c) {
	int res=0;
	res+=x-1-BIT::query(1,x-1);
	res-=BIT::query(x+1,n);
	//printf("? %d\n",res);
	for (int i=0;i<26;i++) if (i!=c) {
		int p=lower_bound(g[i].begin(),g[i].end(),x)-g[i].begin();
		res+=max(0,now[i]-p);
		//if (now[i]-p>0) printf("now=%d,i=%d,p=%d\n",now[i],i,p);
	}
	return res;
}
void SET(int x,int y,int c) {
	assert(p[x]==n);
	ans+=query(x,y,c);
	//printf("ans->%lld\n",ans);
	BIT::add(x);
	p[x]=y;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		read(n); scanf("%s",s+1); scanf("%s",t+1);
		for (int i=0;i<27;i++) g[i].clear(),now[i]=0;
		for (int i=1;i<=n;i++) g[s[i]-'a'].push_back(i);
		sort(s+1,s+n+1);
		int flag=0;
		for (int i=1;i<=n;i++) if (s[i]!=t[i]) { flag=(s[i]<t[i]); break; }
		if (!flag) { puts("-1"); continue; }
		for (int i=1;i<=n;i++) p[i]=n;
		ANS=1e18; ans=0; BIT::init();
		int x,c;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<t[i]-'a';j++) {
				if (now[j]==(int)g[j].size()) continue;
				x=g[j][now[j]];
			//	for (int k=1;k<=n;k++) printf("%d ",p[k]); puts(""); printf("x=%d %d %lld\n",x,query(x,i,j),ans);
				ANS=min(ANS,ans+query(x,i,j));
			}
			if (i==n) break;
			c=t[i]-'a';
			if (now[c]==(int)g[c].size()) break;
			x=g[c][now[c]++];
			SET(x,i,c);
			//printf("SET %d %d\n",x,i);
		}
		printf("%lld\n",ANS);
	}
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