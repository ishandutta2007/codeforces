#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e10;
const int maxn=(2e5)+10;
int T;
ll k,a[maxn],mx;
int n;
bool check() {
	int flag=0;
	for (int i=1;i<=n;i++) {
		if (a[i]<0) return 0;
		if (a[i]==0) flag=1;
	}
	return flag;
}
void move() {
	mx=-INF;
	for (int j=1;j<=n;j++) mx=max(mx,a[j]);
	for (int j=1;j<=n;j++) a[j]=mx-a[j];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(a[i]);
		if (k<=5) {
			for (int i=1;i<=k;i++) move();
		} else {
			while (!check()) {
				move(); k--;
			}
			if (k&1) move();
		}
		for (int j=1;j<=n;j++) printf("%d ",a[j]); puts("");
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/