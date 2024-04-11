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
const int maxn=2010;
int n;
int col[maxn];
struct node {
	double x,y; int id;
	friend node operator + (node A,node B) { return (node){A.x+B.x,A.y+B.y,A.id}; }
	friend node operator - (node A,node B) { return (node){A.x-B.x,A.y-B.y,A.id}; }
	friend double operator * (node A,node B) { return A.x*B.y-A.y*B.x; }
	double len() { return x*x+y*y; }
	friend bool operator < (node t1,node t2) {
		return (t1*t2)>0||((t1*t2)==0&&t1.len()<t2.len());
	}
} delta,p[maxn];
int R[maxn],cnt;
vector<pair<int,int> > ans;
void add(int x,int y) { ans.push_back(MP(x,y)); }
bool on[maxn];
bool In(node p,node a,node b,node c) {
	return abs((b-a)*(c-a))==abs((p-a)*(b-a))+abs((p-c)*(b-c))+abs((p-a)*(c-a));
}
void solve(int a,int b,int c) {
	assert(col[p[a].id]==col[p[b].id]);
	vector<int> vec;
	for (int i=1;i<=n;i++) if (i!=a&&i!=b&&i!=c&&In(p[i],p[a],p[b],p[c])) vec.push_back(i);
	int fd=0;
	for (int &x : vec) if (col[p[x].id]!=col[p[a].id]) {
		fd=x; break;
	}
	if (fd) {
		add(p[fd].id,p[c].id);
		solve(a,b,fd);
		solve(c,fd,b);
		solve(c,fd,a);
	} else {
		for (int &x : vec) add(p[b].id,p[x].id);
	} 
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(p[i].x),read(p[i].y),read(col[i]),p[i].id=i;
	int k=1;
	for (int i=2;i<=n;i++) if (p[i].y<p[k].y||(p[i].y==p[k].y&&p[i].x<p[k].x)) k=i;
	swap(p[k],p[1]);
	delta=p[1];
	for (int i=1;i<=n;i++) p[i]=p[i]-delta;
	sort(p+2,p+n+1);
	R[cnt=1]=1;
	for (int i=2;i<=n;i++) {
		while (cnt>1&&(p[i]-p[R[cnt-1]])*(p[R[cnt]]-p[R[cnt-1]])>=0) cnt--;
		R[++cnt]=i;
	}
	for (int i=1;i<=cnt;i++) R[i+cnt]=R[i]; R[0]=R[cnt];
	int calc=0;
	for (int i=1;i<=cnt;i++) if (col[p[R[i]].id]!=col[p[R[i+1]].id]) calc++;
	if (calc>2) { puts("Impossible"); return 0; }
	if (calc==0) {
		for (int i=1;i<cnt;i++) add(p[R[i]].id,p[R[i+1]].id);
		for (int i=1;i<=cnt;i++) on[R[i]]=1;
		int fd=0;
		for (int i=1;i<=n;i++) if (!on[i]&&col[p[i].id]!=col[p[R[1]].id]) {
			fd=i; break;
		}
		if (fd) {
			for (int i=1;i<=cnt;i++) solve(R[i],R[i+1],fd);
		} else {
			for (int i=1;i<=n;i++) if (!on[i]) add(p[R[1]].id,p[i].id);
		}
	} else {
		int st,ed;
		for (int i=1;i<=cnt;i++) if (col[p[R[i]].id]!=col[p[R[i-1]].id]) {
			st=i; break;
		}
		for (int i=st;;i++) if (col[p[R[i]].id]!=col[p[R[st]].id]) { ed=i-1; break; }
		//for (int i=st;i<=st+cnt-1;i++) printf("%d ",col[p[R[i]].id]); puts("");
		for (int i=ed+1;i<=st+cnt-2;i++) {
			int x=R[i],y=R[i+1];
			add(p[x].id,p[y].id);
			solve(x,y,R[st]);
		}
		for (int i=st;i<ed;i++) {
			int x=R[i],y=R[i+1];
			add(p[x].id,p[y].id);
			solve(x,y,R[ed+1]);
		}
	}
	printf("%d\n",(int)ans.size());
	for (auto [x,y] : ans) printf("%d %d\n",x-1,y-1);
	return 0;
}