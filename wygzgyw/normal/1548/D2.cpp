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
ll cnt[6010][4][4][4];
int n,x[6010],y[6010];
ll s1,s2,ans;
int gcd(int a,int b) {
	if (!a||!b) return a+b;
	return gcd(b,a%b);
}
ll C(ll n) { return n*(n-1)/2; }
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) {
		int t=gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4;
		cnt[i][x[j]%4][y[j]%4][t]++;
		if (i!=j) cnt[j][x[i]%4][y[i]%4][t]++;
	}
	
	for (int i=1;i<=n;i++) {
		cnt[i][x[i]%4][y[i]%4][0]--;
		for (int x1=0;x1<=3;x1++) for (int y1=0;y1<=3;y1++)
		for (int x2=0;x2<=3;x2++) for (int y2=0;y2<=3;y2++) {
			if (x1%2!=x2%2||y1%2!=y2%2) continue;
			int t,t1=(x2-x1+4)%4,t2=(y2-y1+4)%4;
			if (t1==0&&t2==0) t=0; else t=2;
			for (int b1=0;b1<=3;b1++) for (int b2=0;b2<=3;b2++) {
				if (MP(MP(x1,y1),b1)>MP(MP(x2,y2),b2)) continue;
				ll tmp=cnt[i][x1][y1][b1]*cnt[i][x2][y2][b2];
				if (MP(MP(x1,y1),b1)==MP(MP(x2,y2),b2)) tmp=C(cnt[i][x1][y1][b1]);
				if (!tmp) continue;
				int S=x1*y2-x2*y1+x2*y[i]-y2*x[i]+x[i]*y1-y[i]*x1;
				S=(S%4+4)%4;
				if ((b1+b2+t)%2==0&&(b1+b2+t)%4==S) {
					//printf(" %d (%d,%d,%d) (%d,%d,%d) %lld, %d\n",i,x1,y1,b1,x2,y2,b2,tmp,t);
					if (b1%2==0) s1+=tmp;
					else s2+=tmp;
				}
			}
		}
		cnt[i][x[i]%4][y[i]%4][0]++;
	}
	//printf(" %lld %lld\n",s1,s2);
	ans=s1/3+s2;
	printf("%lld\n",ans);
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