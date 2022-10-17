#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 101010;
// template start
typedef long long LL;LL ans,a[N];int M,n,i,L,R,jj,l,tot,p[N],P[N],w[9];struct U{LL x,z;U(){}U(LL x,LL z):x(x),z(z){}};
void exgcd(LL a,LL b,LL &x,LL &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=x*(a/b);}
LL pow(LL a,LL b,LL p){LL sum=1;for(a%=p;b;a=a*a%p,b>>=1)if(b&1)sum=sum*a%p;return sum;}
LL inv(LL a,LL p){LL x,y;exgcd(a,p,x,y);return(x+p)%p;}
U Fac[20][N]; 
U fac(int k,LL n){
    if(!n)return U(1,0);
	return Fac[k][n]; 
}
LL get(int k,LL n,LL m){
    U a=fac(k,n),b=fac(k,m),c=fac(k,n-m);
    return pow(p[k],a.z-b.z-c.z,P[k])*a.x%P[k]*inv(b.x,P[k])%P[k]*inv(c.x,P[k])%P[k];
}
LL CRT(){
    LL d,w,y,x,ans=0;
    for(int i=1;i<=l;i++)w=M/P[i],exgcd(w,P[i],x,y),ans=(ans+w*x*a[i])%M;
    return(ans+M)%M;
}
LL C(LL n,LL m){
	if(m < 0) return 0; 
	if(m > n) return 0; 
    for(int i=1;i<=l;i++)a[i]=get(i,n,m);
    return CRT();
}
// template end
void Init() 
{ 
	for(int i = 1; i <= l; i++) 
	{ 
		Fac[i][0] = U(1, 0); 
		for(int j = 1; j <= 100000; j++) 
		{
			Fac[i][j] = Fac[i][j - 1]; 
			int x = j, cnt = 0; 
			while(x % p[i] == 0) x /= p[i], cnt++; 
			Fac[i][j].z += cnt, (Fac[i][j].x *= x) %= P[i]; 
		}
	}
}
LL Solve() 
{ 
	LL ans = (L == 0) ; 
	int nl = 0, nr = 0; 
	LL lastans = 1; 
	for(int x = 1; x <= n; x++) 
	{
	   LL ll = (x + L + 1) / 2, lr = min(x, (x + R) / 2), tmp = 0; 
	   if(ll > lr) continue; 
	   if(ll == lr)
	   { 
		   tmp = C(x, ll); 
	   }
	   else
	   {
		   tmp = lastans * 2 % M; 
		   if(nl == ll) tmp = (tmp + C(x - 1, nl - 1)) % M; 
		   else tmp = (tmp - C(x - 1, nl) + M) % M; 
		   if(nr == lr) tmp = (tmp - C(x - 1, nr) + M) % M; 
		   else
		   {
			   tmp += C(x - 1, lr); 
			   tmp %= M;
		   }
	   }

	   nl = ll, nr = lr; 
	   ans = (ans + tmp * C(n, x) % M) % M;
	   lastans = tmp; 
	}
	return ans; 
}

int main() 
{
    for(scanf("%d%d%d%d",&n,&M,&L,&R),jj=M,i=2;i*i<=jj;i++)if(jj%i==0)
        for(p[++l]=i,P[l]=1;jj%i==0;P[l]*=p[l])jj/=i;
    if(jj>1)l++,p[l]=P[l]=jj;
	Init(); 
	LL ans = Solve(); 
	L += 2, R += 2; 
	ans = (ans - Solve() + M) % M; 
	cout << ans << endl; 
}