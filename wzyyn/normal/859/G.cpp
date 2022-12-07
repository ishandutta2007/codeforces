#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
char s[N];
int n,di[15];
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
bool ispri(int x){
	if (x<=1) return 0;
	for (int i=2;1ll*i*i<=x;++i)
		if (x%i==0) return 0;
	return 1;
}
int getg(int x){
	int y=x-1; *di=0;
	for (int i=2;i*i<=y;i++)
		if (y%i==0){
			di[++*di]=i;
			for (;y%i==0;y/=i);
		}
	if (y!=1) di[++*di]=y;
	for (int g=2;;++g){
		bool flg=0;
		For(i,1,*di)
			if (power(g,(x-1)/di[i],x)==1)
				flg=1;
		if (!flg) return g;
	}
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n) s[i]-='0';
	int u=clock();
	for (int p=1;1.0*clock()/CLOCKS_PER_SEC<=0.2;){
		for (p+=n;p<=1e9&&!ispri(p);p+=n);
		int v=getg(p),s=0,a=1;
		v=power(v,(p-1)/n,p);
		For(i,1,n) s=(s+1ll*::s[i]*a)%p,a=1ll*a*v%p;
		if (s) return puts("NO"),0;
	}
	puts("YES");
}