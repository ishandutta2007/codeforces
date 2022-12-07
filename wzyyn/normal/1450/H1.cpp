#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
const int mo=998244353;
int fac[N],inv[N];
int n,m,s0,s1,s2;
char s[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int F(){
	int ts2=s2-s0,ans=0;
	For(i,0,s0+s1) if ((ts2+i)%2==0)
		ans=(ans+1ll*abs(ts2+i)*C(s0+s1,i))%mo;
	return 1ll*ans*power(2,mo-1-s0-s1)%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	For(i,1,n)
		if (s[i]=='?')
			(i&1?++s1:++s0);
		else if (s[i]=='w')
			(i&1?++s2:--s2);
	cout<<F()<<endl;
}