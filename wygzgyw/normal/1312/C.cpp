#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,n,k,vis[100];
ll x;
int cnt;
bool flag;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k);
		memset(vis,0,sizeof(vis));
		flag=1;
		for (int i=1;i<=n;i++) {
			read(x);
			if (!flag) continue;
			cnt=0;
			while (x) {
				if (x%k>1) { flag=0; break; }
				if (x%k==1) {
					if (vis[cnt]) { flag=0; break; }
					vis[cnt]=1;
				}
				x/=k; cnt++;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/