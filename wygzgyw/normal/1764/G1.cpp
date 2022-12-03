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
const int maxn=1200;
int n,p[maxn];
bool flag=0;
bool v1[maxn],v2[maxn];
int r1[maxn],r2[maxn];
int d[maxn],tot;
int Query(int l,int r,int k) {
	tot=0; for (int i=l;i<=r;i++) d[++tot]=p[i]/k;
	sort(d+1,d+tot+1); tot=unique(d+1,d+tot+1)-d-1; return tot;
}
int cnt;
int query(int l,int r) {
	if (l>r) return 0;
	if (l==1&&r==n) return n%2==0?2:1;
	if (l==1&&v1[r]) return r1[r];
	if (r==n&&v2[l]) return r2[l];
	cnt++;
	printf("? %d %d 2\n",l,r); fflush(stdout);
	int x;
	if (flag) x=Query(l,r,2);
	else scanf("%d",&x);
	x=r-l+1-x;
	x=r-l+1-2*x;
	if (l==1) v1[r]=1,r1[r]=x;
	if (r==n) v2[l]=1,r2[l]=x;
	return x;
}
bool In(int l,int r) {
	if (l>r) return 0;
	cnt++;
	printf("? %d %d %d\n",l,r,n); fflush(stdout);
	int x;
	if (flag) x=Query(l,r,n);
	else scanf("%d",&x);
	return x==2;
}
int main() {
	srand(time(0));
	scanf("%d",&n);
	if (flag) { for (int i=1;i<=n;i++) p[i]=i; random_shuffle(p+1,p+n+1); }
	
	if (flag) {
		for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
	}
	
	int l=1,r=n;
	if (n%2==1) {
		int res;
		while (l<=r) {
			int mid=(l+r)>>1;
			int x=query(1,mid),y=query(mid+1,n);
			if (x==y+1) res=mid,r=mid-1; else l=mid+1;
		}
		printf("! %d\n",res); fflush(stdout);
		if (flag) assert(p[res]==1); return 0;
	}
	int F=-1;
	int res=-1;
	while (r-l+1>1) {
		int mid=(l+r)>>1;
		int x=query(1,mid),y=query(mid+1,n);
		if (F!=-1) {
			if (!F) x--; else y--;
			if (x==y+1) r=mid-1,res=mid;
			else l=mid+1;
			continue;
		}
		if (x==y+2) r=mid-1,res=mid;
		else if (y==x+2) l=mid+1;
		else {
			if (mid>=2) {
				if (In(1,mid)) l=mid+1,F=0; else r=mid-1,res=mid,F=1;
			} else if (In(mid+1,n)) r=mid-1,res=mid,F=1; else l=mid+1,F=0;
		}
	}
	if (res!=-1) r=res;
	int ans;
	//printf("%d %d\n",l,r);
	if (query(1,l-1)==query(1,r)) {
	//	puts("-1");
		if (query(1,l-1)<query(1,l)) ans=l; else ans=r;
	} else if (query(l,n)==query(r+1,n)) {
	//	puts("-2");
		if (query(r+1,n)<query(r,n)) ans=r; else ans=l;
	} else {
		if (l>1) {
			if (In(1,l)) ans=r; else ans=l;
		} else if (In(r,n)) ans=l; else ans=r;
	}
	printf("! %d\n",ans); fflush(stdout);
	if (flag) assert(p[ans]==1),cerr<<cnt<<endl;
	return 0;
}