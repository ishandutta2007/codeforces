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
const int maxn=(1e6)+10;
pair<int,int> X[maxn],Y[maxn];
vector<pair<int,int> > v;
int n,m;
pair<int,int> lca(pair<int,int> x,pair<int,int> y) {
	//printf("in %d %d, %d %d\n",x.first,x.second,y.first,y.second);
	pair<int,int> res=MP(0,0);
	for (int i=29;i>=0;i--) {
		int t1=0,t2=0;
		if ((x.first>>i)&1) t1++; if ((x.second>>i)&1) t1+=2;
		if ((y.first>>i)&1) t2++; if ((y.second>>i)&1) t2+=2;
		if (t1==t2) {
			if (t1==1) res.first+=(1<<i);
			else if (t1==2) res.second+=(1<<i);
			x.first&=((1<<i)-1),y.first&=((1<<i)-1);
			x.second&=((1<<i)-1),y.second&=((1<<i)-1);
			continue;
		}
		//printf(" %d %d %d\n",i,t1,t2);
		if (t1+t2==3) {
		//	printf("res=%d %d\n",res.first,res.second);
			return res;
		}
		if (t1==0) swap(x,y),swap(t1,t2);
		if (t1==1) {
			x.first=(1<<i)-1;
			x.second=0;
		} else {
			x.first=0;
			x.second=(1<<i)-1;
		}
		//if (i<=4) printf("%d %d,%d %d\n",x.first,x.second,y.first,y.second);
	}
	x.first+=res.first,x.second+=res.second;
	//printf("res=%d %d\n",x.first,x.second);
	return x;
}
bool cmp(pair<int,int> x,pair<int,int> y) {
	for (int i=29;i>=0;i--) {
		int t1=0,t2=0;
		if ((x.first>>i)&1) t1++; if ((x.second>>i)&1) t1+=2;
		if ((y.first>>i)&1) t2++; if ((y.second>>i)&1) t2+=2;
		if (t1==t2) continue;
		if (t1==2||t2==2) return t2==2;
		if (t1==0) return (x.second&((1<<i)-1))==0;
		return (y.second&((1<<i)-1))!=0;
	}
	return 0;
}
pair<int,int> dy[maxn]; vector<int> g[maxn];
int f[maxn],cnt[maxn]; map<int,int> xyr;
map<pair<int,int>,int> M;
int dep[maxn];
void dfs(int u) {
	int now=0;
	//printf("u=%d\n",u);
	for (int v : g[u]) {
		dfs(v);
		//printf("> %d %d\n",u,v);
		if (f[v]) {
			xyr[dep[v]]^=1,xyr[dep[u]+1]^=1;
		}
		now+=f[v];
	}
	if (now||f[u]||cnt[u]) {
		xyr[dep[u]]^=1,xyr[dep[u]+1]^=1;
	}
	f[u]+=now;
}
int main() {
	//freopen("1.txt","r",stdin);
	
	/*int x1,y1,x2,y2;
	read(x1),read(y1),read(x2),read(y2);
	pair<int,int> A=lca({x1,y1},{x2,y2});
	printf("%d %d\n",A.first,A.second);
	exit(0);
	*/read(m);
	for (int i=1;i<=m;i++) {
		read(X[i].first),read(X[i].second);
		read(Y[i].first),read(Y[i].second);
		v.push_back(X[i]),v.push_back(Y[i]);
	}
	sort(v.begin(),v.end(),cmp);
	v.erase(unique(v.begin(),v.end()),v.end());
	int sz=(int)v.size();
	for (int i=0;i+1<sz;i++) v.push_back(lca(v[i],v[i+1]));
	sort(v.begin(),v.end(),cmp);
	v.erase(unique(v.begin(),v.end()),v.end());
	//puts("---");
	stack<int> s;
	for (pair<int,int> A : v) {
		//printf(">>> %d %d %d\n",A.first,A.second,(int)s.size());
		while (!s.empty()&&lca(dy[s.top()],A)!=dy[s.top()]) s.pop();
		n++; dy[n]=A;
		if (!s.empty()) g[s.top()].push_back(n);
		s.push(n);
	}
	//for (pair<int,int> A : v) printf("%d %d\n",A.first,A.second);
	for (int i=1;i<=n;i++) M[dy[i]]=i,dep[i]=dy[i].first+dy[i].second;
	for (int i=1;i<=m;i++) {
		int x=M[X[i]],y=M[Y[i]];
		if (X[i]==Y[i]) cnt[x]++;
		f[x]++,f[y]++,f[M[lca(X[i],Y[i])]]-=2;
	}
	dfs(1); int ans=0;
	for (pair<int,int> A : xyr) if (A.first!=0) ans+=A.second;
	printf("%d\n",ans);
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