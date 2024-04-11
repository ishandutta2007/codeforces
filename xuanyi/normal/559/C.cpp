#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=2005;
const int MAXH=200005;
const int MOD=1000000007;

int n,f[MAXN],fac[MAXH],inv[MAXH];

struct point{
	int x,y;
	bool operator <(const point &b)const{
		return x^b.x?x<b.x:y<b.y;
	}
} a[MAXN];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x; 
}

inline int calc_inv(int a){
	int s=1,b=MOD-2;
	while (b){
		if (b&1) s=(ll)s*a%MOD;
		a=(ll)a*a%MOD;
		b>>=1;
	}
	return s;
}

inline void pre(){
	fac[0]=1; inv[0]=1;
	for (int i=1;i<MAXH;i++){
		fac[i]=(ll)fac[i-1]*i%MOD;
		inv[i]=calc_inv(fac[i]);
	}
}

inline int calc_dis(int a,int b){
//	printf("calc : %d %d %d\n",a,b,(ll)fac[a+b]*inv[a]%MOD*inv[b]%MOD);
	return (ll)fac[a+b]*inv[a]%MOD*inv[b]%MOD;
}

int main(){
	pre();
	read(a[0].x),read(a[0].y),read(n);
	for (int i=1;i<=n;i++)
		read(a[i].x),read(a[i].y);
	sort(a,a+1+n);
	for (int i=0;i<=n;i++){
		f[i]=calc_dis(a[i].x-1,a[i].y-1);
		for (int j=0;j<i;j++)
			if (a[j].x<=a[i].x && a[j].y<=a[i].y){
				f[i]=(f[i]-(ll)f[j]*calc_dis(a[i].x-a[j].x,a[i].y-a[j].y)%MOD)%MOD;
			}
		f[i]=(f[i]+MOD)%MOD;
	}
	printf("%d\n",f[n]);
	return 0;
}