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
const int maxn=(2e5)+10;
int n,a[maxn];
int mn[maxn],mx[maxn],ans;
vector<pair<int,int> > V;
int ban[maxn],nxt[maxn];
int query(int l,int r) {
	int L=-1,R=-1,cnt=0,LST=-1;
	for (int i=r;i>=l;i--) if (!ban[i]) { nxt[i]=i; if (LST==-1) LST=i; } else nxt[i]=nxt[i+1];
//	for (int i=l;i<=r;i++) if (!ban[i]) printf("i=%d\n",i);
	for (int i=l;i<=r;i++) if (!ban[i]) {
		if (L==-1) L=V[i].first,R=V[i].second,cnt++;
		else {
			if (i==LST||V[nxt[i+1]].first>R) cnt++,R=V[i].second;
		}
		//printf("i=%d\n",i);
	}
//	printf("l=%d r=%d\n",l,r);
//	printf("%d %d\n",L,R);
	return R-L-cnt;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),mx[a[i]]=i;
	for (int i=n;i>=1;i--) mn[a[i]]=i;
	for (int i=1;i<=n;i++) if (mn[i]&&mn[i]!=mx[i]) {
		V.push_back(MP(mn[i],mx[i]));
	}
	sort(V.begin(),V.end());
	int l=-1,r=-1,cnt=0,fst=0,i=0;
	//for (pair<int,int> &A : V) printf("%d %d\n",A.first,A.second);
	for (pair<int,int> &A : V) {
		if (l==-1) fst=i,l=A.first,r=A.second,cnt=1;
		else if (A.second>r) {
			if (A.first>r) ans+=query(fst,i-1),fst=i,l=A.first,r=A.second,cnt=1;
			else r=A.second,cnt++;
		} else ban[i]=1;
		i++;
	}
	if (l!=-1) ans+=query(fst,(int)V.size()-1);
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