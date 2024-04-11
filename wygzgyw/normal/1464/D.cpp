#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int INF=1e9;
const int maxn=(1e6)+10;
int T,n,p[maxn],a[maxn],vis[maxn];
int s1,s2,c1,c2,c3,c;
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int solve(int a,int b) {
	if (a>b) return b+(a-b)/3*2;
	return a+(b-a)/3*3;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]),a[i]=vis[i]=0;
		s1=s2=0;
		for (int i=1;i<=n;i++)
			if (!vis[i]) {
				int j=i,cnt=0;
				while (1) {
					vis[j]=1;
					cnt++;
					if (p[j]==i) break;
					j=p[j];
				}
				a[cnt]++;
			}
		if (n%3==1) {
			s1=(ll)4*ksm(3,(n-4)/3)%mod;
			c1=a[1],c2=a[2],c3=INF;
			for (int i=3;i<=n;i++) {
				s2+=((i+2)/3-1)*a[i];
				if (i%3==1) c1+=a[i];
				if (i%3==2) c2+=a[i];
			}
			if (c1/2+c2>=2) {
				c=min(c2,2);
				c3=min(c3,solve(c1-2*(2-c),c2-c)+2-c);
			}
			if (c1) c3=min(c3,solve(c1-1,c2)+1);
			for (int i=4;i<=n;i+=3) if (a[i]) {
				c3=min(c3,solve(c1-1,c2)-1);
				break;
			}
			s2+=c3;
		} else {
			s1=ksm(3,n/3);
			if (n%3==2) s1=(ll)s1*2%mod;
			c1=a[1],c2=a[2];
			for (int i=3;i<=n;i++) {
				s2+=((i+2)/3-1)*a[i];
				if (i%3==1) c1+=a[i];
				if (i%3==2) c2+=a[i];
			}
			if (n%3==2) {
				if (c2) s2+=solve(c1,c2-1);
				else s2+=solve(c1-2,c2)+1;
			} else s2+=solve(c1,c2);
		}
		printf("%d %d\n",s1,s2);
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