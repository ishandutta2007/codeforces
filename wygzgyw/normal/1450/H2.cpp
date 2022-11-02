#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(3e5)+10;
int n,q,a,b;
char s[maxn];
int ivmi[maxn];
int ivjc[maxn],jc[maxn],iv[maxn];
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
struct node {
	int x,y,res;
	void init() { x=y=0; res=1; }
	int query(int L,int R) {
		while (y<R) y++,update(res,C(x,y));
		while (y>R) update(res,mod-C(x,y)),y--;
		while (x<L) x++,res=res*2%mod,update(res,mod-C(x-1,y));
		while (x>L) res=(ll)(res+C(x-1,y))*iv[2]%mod,x--;
		return res;
	}
} p[4];
int S(int x,int y,int op) {
	if (x==-1) return y>=0&&y%2==0;
	return p[op].query(x,y);
	int res=0;
	for (int i=0;i<=y;i++) update(res,C(x,i));
	return res;
}
void solve() {
	ll res=(ll)b*S(a-1,b-2,0)%mod-(ll)a*S(a-2,b-3,1)%mod+(ll)a*S(a-2,a-b-2,2)%mod-(ll)b*S(a-1,a-b-2,3)%mod;
	res=(res%mod+mod)%mod;
	//printf("%d %d %d\n",res,a,ivmi[a]);
	printf("%lld\n",res*ivmi[a]%mod);	
}
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=0;i<4;i++) p[i].init();
	read(n),read(q);
	iv[0]=ivjc[0]=jc[0]=iv[1]=ivjc[1]=jc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	ivmi[0]=1,ivmi[1]=iv[2];
	for (int i=2;i<maxn;i++) ivmi[i]=(ll)ivmi[i-1]*iv[2]%mod;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='?') a++;
		else if ((s[i]=='w')!=i%2) b++;
	b=n/2-b;
	solve();
	int x; char ch;
	while (q--) {
		scanf("%d %c",&x,&ch);
		if (s[x]=='?') a--;
		else if ((s[x]=='w')!=x%2) b++;
		s[x]=ch;
		if (s[x]=='?') a++;
		else if ((s[x]=='w')!=x%2) b--;
		solve();
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