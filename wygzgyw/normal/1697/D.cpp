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
const int maxn=1010;
const int flag=0;
char s[maxn];
int cnt[30];
int T,n,ans[maxn][maxn];
int query(int l,int r) {
	if (ans[l][r]) return ans[l][r];
	T++;
	if (flag) {
		int res=0;
		memset(cnt,0,sizeof(cnt));
		for (int i=l;i<=r;i++) {
			if (!cnt[s[i]-'a']) cnt[s[i]-'a']=1,res++;
		}
		ans[l][r]=res;
		return res;
	}
	printf("? 2 %d %d\n",l,r); fflush(stdout);
	int x; scanf("%d",&x); return ans[l][r]=x;
}
int lst[maxn];
char t[maxn];
int d[maxn],tot;
char ch[5];
char Query(int x) {
	if (flag) return s[x];
	printf("? 1 %d\n",x); fflush(stdout);
	scanf("%s",ch); return ch[0];
}
int main() {
	if (flag) {
		n=1000;
		for (int i=1;i<=n;i++) s[i]=rand()%26+'a';
//		scanf("%s",s+1);
	}
	else scanf("%d",&n);
	d[tot=1]=1;
	for (int i=2;i<=n;i++) {
		sort(d+1,d+tot+1);
		int l=1,r=tot,mid,res=0;
		while (l<=r) {
			mid=(l+r)>>1;
			if (tot-mid+1==query(d[mid],i)) res=mid,l=mid+1;
			else r=mid-1;
		}
		if (!res) d[++tot]=i;
		else lst[i]=d[res],d[res]=i;
	}
	if (flag) cerr<<T<<endl;
	for (int i=1;i<=n;i++) {
		if (lst[i]) t[i]=t[lst[i]];
		else t[i]=Query(i);
	}
	if (flag) { for (int i=1;i<=n;i++) assert(s[i]==t[i]); }
	else printf("! %s\n",t+1);
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