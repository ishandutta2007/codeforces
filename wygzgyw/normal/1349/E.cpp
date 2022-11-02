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
int n;
ll t[maxn];
struct node {
	int l,r,op;
} b[maxn]; int tot;
int a[maxn],cnt;
int f[maxn][2],from[maxn][2];
vector<int> vec[maxn][2];
int ans[maxn];
ll S(int l,int r) { return (ll)(l+r)*(r-l+1)/2; }
bool check(ll s,int l,int r) {
	if (s<=0) return s==0&&r-l+1>=0;
	if (l>r) return 0;
	int L=1,R=r-l+1,mid;
	while (L<=R) {
		mid=(L+R)>>1;
		if (S(l,l+mid-1)<=s) L=mid+1; else R=mid-1;
	}
	mid=L-1;
	return S(r-mid+1,r)>=s;
}
void gen(vector<int> &vec,ll s,int l,int r) {
	if (s==0) return;
	int L=1,R=r-l+1,mid;
	while (L<=R) {
		mid=(L+R)>>1;
		if (S(n-r+1,n-r+1+mid-1)<=s) L=mid+1; else R=mid-1;
	}
	mid=L-1;
	for (int i=r;i>=l&&s;i--) {
		if (S(n-i+2,n-i+mid)<=s-(n-i+1)&&S(n-l+1-(mid-1)+1,n-l+1)>=s-(n-i+1)) {
			mid--,s-=n-i+1,vec.push_back(i);
		}
	}
}
void update(int i,int j,int J,int pos) {
	if (f[i][j]!=-1&&f[i][j]<=pos) return;
	f[i][j]=pos; from[i][j]=J;
	vec[i][j].clear(),vec[i][j].push_back(pos);
	gen(vec[i][j],t[b[i].r]+j-t[b[i-1].r]-J-n+pos-1,f[i-1][J]+1,b[i].l-1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(t[i]);
		if (t[i]) a[++cnt]=i;
	}
	if (!cnt) {
		for (int i=1;i<=n;i++) printf("0"); puts(""); return 0;
	}
	b[tot=1]=(node){a[1],a[1],0};
	for (int i=2;i<=cnt;i++) {
		if (t[a[i]]==t[b[tot].r]) b[tot].r=a[i],b[tot].op=1;
		else if (t[a[i]]==t[b[tot].r]-1) b[tot].r=a[i],b[tot].op=2;
		else b[++tot]=(node){a[i],a[i],0};
	}
	b[tot+1].l=n+2;
	memset(f,-1,sizeof(f));
	f[0][1]=0;
	for (int i=1;i<=tot;i++) {
		for (int j=0;j<2;j++) if (f[i-1][j]!=-1) {
			if (b[i].op!=2) {
				ll tmp=t[b[i].r]-1-(t[b[i-1].r]-(1-j));
				int fd=-1;
				for (int pos=max((ll)b[i].r+1,n-tmp+1);pos<b[i+1].l;pos++)
					if (check(tmp-(n-pos+1),n-b[i].l+2,n-f[i-1][j])) { fd=pos; break; }
				if (fd!=-1) update(i,0,j,fd);
			}
			if (b[i].op!=1) {
				ll tmp=t[b[i].r]-(t[b[i-1].r]-(1-j));
				int pos=b[i].r;
				if (check(tmp-(n-pos+1),n-b[i].l+2,n-f[i-1][j])) update(i,1,j,pos);
			}
		}
	}
	if (f[tot][0]==-1&&f[tot][1]==-1&&b[tot].op==1) {
		//puts("OK");
		int i=tot;
		for (int j=0;j<2;j++) if (f[i-1][j]!=-1) {
			ll tmp=t[b[i].r]-1-(t[b[i-1].r]-(1-j));
			int fd=-1;
			for (int pos=max((ll)b[i].l,n-tmp+1);pos<=b[i].r;pos++)
				if (!t[pos]&&check(tmp-(n-pos+1),n-b[i].l+2,n-f[i-1][j])) { fd=pos; break; }
			if (fd!=-1) update(i,0,j,fd);
		}
	}
	int j=(f[tot][0]!=-1?0:1);
	//printf("?%d\n",f[tot][j]);
	for (int i=tot;i>=1;i--) {
		//printf("%d %d\n",i,j);
		for (int &x : vec[i][j]) ans[x]=1;
		j=from[i][j];
	}
	for (int i=1;i<=n;i++) printf("%d",ans[i]); puts("");
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