#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define pc putchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 1e5+233;
int a[2][maxn],tmp[2][maxn];
int n,m;
int ans = 0;
int cnt[2][2];
#define max(a,b) ((a) < (b) ? (b) : (a))
inline void solve(int l0,int r0,int l1,int r1){
	if((l0>r0) || (l1>r1)){
		if(l0<=r0) ans = max(ans,r0-l0+1);
		if(l1<=r1) ans = max(ans,r1-l1+1);
		return ;
	}
	if(a[0][r0]==0&&a[1][r1]==0) return ;
	Rep(i,l0,r0) tmp[0][i] = a[0][i];
	Rep(i,l1,r1) tmp[1][i] = a[1][i];
	cnt[0][0]=cnt[0][1]=cnt[1][0]=cnt[1][1]=0;
	Rep(i,l0,r0)
		if(i==l0 || a[0][i] != a[0][i-1])
			cnt[0][a[0][i]&1]++;

	Rep(i,l1,r1)if(i==l1 || a[1][i] != a[1][i-1])cnt[1][a[1][i]&1]++;
	ans = max(max(ans,cnt[0][0]+cnt[1][1]),cnt[0][1]+cnt[1][0]);
	int L0 = l0,R0 = r0;
	Rep(i,l0,r0)if(tmp[0][i]&1)a[0][L0++] = tmp[0][i]>>1;
	Dep(i,r0,l0)if(!(tmp[0][i]&1))a[0][R0--] = tmp[0][i]>>1;
	int L1 = l1,R1 = r1;
	Rep(i,l1,r1)if(tmp[1][i]&1) a[1][L1++] = tmp[1][i]>>1;
	Dep(i,r1,l1)if(!(tmp[1][i]&1))a[1][R1--] = tmp[1][i]>>1;
	solve(l0,L0-1,l1,L1-1);
	solve(R0+1,r0,R1+1,r1);
}
int main(){
	n = rd();rd();
	ans = 0;
	Rep(i,1,n) a[0][i]=rd();
	sort(a[0]+1,a[0]+1+n);
	m = rd();rd();
	Rep(i,1,m) a[1][i]=rd();
	sort(a[1]+1,a[1]+1+m);
	if(n==1&&m==1&&a[0][1]==a[1][1]){
		puts("2");
		return 0;
	}
	solve(1,n,1,m);
	writeln(ans);
	return 0;
}