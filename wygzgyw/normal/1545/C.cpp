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
const int mod=998244353;
int T,n,a[1010][510];
bool del[510],ex[510][510];
vector<int> ans;
int cnt,C[510];
void CHOSE(int x) {
	del[x]=1;
	ans.push_back(x);
	for (int i=1;i<=n*2;i++) if (!del[i]) {
		for (int j=1;j<=n;j++) if (a[x][j]==a[i][j]) { del[i]=1; break; }
	}
	for (int i=1;i<=n;i++) ex[i][a[x][i]]=1;
}
bool solve() {
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n*2;j++) if (!del[j]) C[a[j][i]]++;
		for (int j=1;j<=n*2;j++) if (!del[j]&&C[a[j][i]]==1&&!ex[i][a[j][i]]) {
			CHOSE(j);
			for (int k=1;k<=n;k++) C[k]=0;
		//	printf("Had %d\n",j);
			return 1;
		}
		for (int k=1;k<=n;k++) C[k]=0;
	}
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n*2;i++) {
			del[i]=0;
			for (int j=1;j<=n;j++) read(a[i][j]);
		}
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) ex[i][j]=0;
		ans.clear(); cnt=1;
		while ((int)ans.size()<n) {
			if (!solve()) {
				cnt=(ll)cnt*2%mod;
				for (int i=1;i<=n*2;i++) if (!del[i]) { CHOSE(i); break; }
			}
		}
		printf("%d\n",cnt); sort(ans.begin(),ans.end()); for (int x : ans) printf("%d ",x); puts("");
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