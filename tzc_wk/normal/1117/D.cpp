//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
const int MOD=1e9+7;
int n=read(),m=read();
struct matrix{
	int a[105][105];
	matrix(){
		fill0(a);
	}
	inline matrix operator *(matrix b){
		matrix ans;
		fz(i,1,m){
			fz(j,1,m){
				fz(k,1,m){
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*b.a[k][j]%MOD)%MOD;
				}
			}
		}
		return ans;
	}
};
signed main(){
	matrix t,k;
	fz(i,1,m-1)	t.a[i+1][i]=1;
	t.a[1][m]=t.a[m][m]=1;
	fz(i,1,m)	k.a[1][i]=1;
	matrix ans;
	fz(i,1,m)	ans.a[i][i]=1;
	while(n){
		if(n%2)	ans=ans*t;
		t=t*t;
		n>>=1;
	}
//	fz(i,1,m){
//		fz(j,1,m)	cout<<ans.a[i][j]<<" ";
//		puts("");
//	}
	k=k*ans;
	cout<<k.a[1][1]<<endl;
	return 0;
}