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
int n,m,a[maxn],b[maxn];
int s,t;
int bd[maxn];
ll A[maxn],B[maxn];
ll s1[maxn],s2[maxn],suf[maxn];
int top,st[maxn];
bool check(ll *B,int x,int y,int z) {
	return (B[z]-B[y])*(y-x)>=(B[y]-B[x])*(z-y);
}
void build(ll *B,int l) {
	top=0;
	for (int b=l;b<=m;b++) {
		while (top>1&&check(B,st[top-1],st[top],b)) top--;
		st[++top]=b;
	}
}
bool check(int mid) {
	ll m1=0,m2=0;
	ll c1=0,c2=0;
	for (int i=1;i<=n;i++) bd[i]=upper_bound(b+1,b+m+1,mid-a[i])-b-1,c1+=bd[i];
	c2=(ll)n*m-c1;
	m1=max(c1,c2);
	m2=max(c1,c2-1);
	
	for (int i=0;i<=m+1;i++) s1[i]=s2[i]=0;
	for (int i=1;i<=n;i++) s1[bd[i]]++,s2[bd[i]]+=bd[i];
	for (int i=1;i<=m;i++) s1[i]+=s1[i-1],s2[i]+=s2[i-1];

	for (int b=1;b<=m;b++) {
		B[b]=s2[b]+(n-s1[b])*b;
	//	ll tmp=0; for (int i=1;i<=n;i++) tmp+=min(b,bd[i]); assert(B[b]==tmp);
	}
	
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+m-bd[i];
	
	build(B,1);
	
//	for (int i=1;i<=top;i++) printf("%d ",st[i]); puts("");
	for (int a=1;a<=n;a++) {
		ll coef=suf[a+1],k=n-a;
		int l=2,r=top,mid,res=1;
		while (l<=r) {
			mid=(l+r)>>1;
			if ((B[st[mid]]-B[st[mid-1]])>=k*(st[mid]-st[mid-1])) res=mid,l=mid+1; else r=mid-1;
		}
	//	if (a==6) printf("%d\n",st[res]);
		coef+=B[st[res]]-k*st[res];
		m1=max(m1,coef);
		if (a>=s) m2=max(m2,coef);
	}
	
	build(B,t);
	
	
	for (int a=1;a<=n;a++) {
		ll coef=suf[a+1],k=n-a;
		int l=2,r=top,mid,res=1;
		while (l<=r) {
			mid=(l+r)>>1;
			if ((B[st[mid]]-B[st[mid-1]])>=k*(st[mid]-st[mid-1])) res=mid,l=mid+1; else r=mid-1;
		}
		coef+=B[st[res]]-k*st[res];
		m2=max(m2,coef);
	}

	for (int b=1;b<=m;b++) A[b]=B[b];
	for (int b=1;b<t;b++) A[b]--;
	
	build(A,1);
	
	for (int a=1;a<s;a++) {
		ll coef=suf[a+1],k=n-a;
		int l=2,r=top,mid,res=1;
		while (l<=r) {
			mid=(l+r)>>1;
			if ((A[st[mid]]-A[st[mid-1]])>=k*(st[mid]-st[mid-1])) res=mid,l=mid+1; else r=mid-1;
		}
		coef+=A[st[res]]-k*st[res];
		m2=max(m2,coef);
	}
	/*
	for (int a=1;a<=n;a++) {
		for (int b=1;b<=m;b++) {
			ll tmp=0;
			for (int i=1;i<=a;i++) tmp+=min(bd[i],b);
			for (int i=a+1;i<=n;i++) tmp+=m+min(bd[i],b)-bd[i]-b; //min(m-bd[i],m-b)
			m1=max(m1,tmp);
			if (s>a&&t>b) tmp--;
			m2=max(m2,tmp);
		}
	}*/
	
//printf("%lld %lld\n",m1,m2);
	return m1!=m2+1;
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=m;i++) read(b[i]);
	int a1=a[1],b1=b[1];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	s=lower_bound(a+1,a+n+1,a1)-a;
	t=lower_bound(b+1,b+m+1,b1)-b;
//	check(667); return 0;
	int l=2,r=a1+b1-1,mid,res=a1+b1;
	while (l<=r) {
		mid=(l+r)>>1;
		if (check(mid)) res=mid,r=mid-1; else l=mid+1;
	}
	printf("%d\n",res);
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