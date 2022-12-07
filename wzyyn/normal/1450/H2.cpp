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
struct Querier{
	int s0,l0,r0,re0;
	int s1,l1,r1,re1;
	Querier(){
		l0=r0=s0=0; re0=1;
		l1=r1=s1=0; re1=1;
	}
	int SC0(int s,int l,int r){
		s--; l=max(l-1,0); r=min(r,s);
		for (;s0<s;s0++) re0=(2ll*re0+C(s0,l0-1)+mo-C(s0,r0))%mo;
		for (;s0>s;s0--) re0=1ll*(mo+1)/2*(re0+1ll*mo-C(s0-1,l0-1)+C(s0-1,r0))%mo;
		for (;l0>l;--l0,re0=(re0+C(s0,l0))%mo);
		for (;r0<r;++r0,re0=(re0+C(s0,r0))%mo);
		for (;l0<l;re0=(re0+mo-C(s0,l0))%mo,++l0);
		for (;r0>r;re0=(re0+mo-C(s0,r0))%mo,--r0);
		return re0;
	}
	int SC1(int s,int l,int r){
		
		//cout<<s<<' '<<l<<' '<<r<<endl;
		s--; l--; r--;
		if (l<0) l+=2;
		if (l>r) return 0;
		if (s==0) return 1;
		
		s--; l=max(l-1,0); r=min(r,s);
		for (;s1<s;s1++) re1=(2ll*re1+C(s1,l1-1)+mo-C(s1,r1))%mo;
		for (;s1>s;s1--) re1=1ll*(mo+1)/2*(re1+1ll*mo-C(s1-1,l1-1)+C(s1-1,r1))%mo;
		for (;l1>l;--l1,re1=(re1+C(s1,l1))%mo);
		for (;r1<r;++r1,re1=(re1+C(s1,r1))%mo);
		for (;l1<l;re1=(re1+mo-C(s1,l1))%mo,++l1);
		for (;r1>r;re1=(re1+mo-C(s1,r1))%mo,--r1);
		//cout<<1ll*re1*(s+2)%mo<<endl;
		return 1ll*re1*(s+2)%mo;
	}
}Q0,Q1;
int F(){
	int L=s2-s0,ans=0;
	if (L<=0){
		int l=0,r=min(s0+s1,-L);
		if ((l+L)&1) ++l;
		if ((r+L)&1) --r;
		if (l<=r){
			ans=(ans+1ll*(-L)*Q0.SC0(s0+s1,l,r))%mo;
			ans=(ans+mo-Q0.SC1(s0+s1,l,r))%mo;
		}
	}
	if (L+s0+s1>0){
		int l=max(0,1-L),r=s0+s1;
		if ((l+L)&1) ++l;
		if ((r+L)&1) --r;
		if (l<=r){
			ans=(ans+1ll*(mo+L)*Q1.SC0(s0+s1,l,r))%mo;
			ans=(ans+Q1.SC1(s0+s1,l,r))%mo;
		}
	}
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
	printf("%d\n",F());
	while (m--){
		int x;
		char t[10];
		scanf("%d%s",&x,t+1);
		if (s[x]=='?') (x&1?--s1:--s0);
		if (s[x]=='w') (x&1?--s2:++s2);
		s[x]=t[1];
		if (s[x]=='?') (x&1?++s1:++s0);
		if (s[x]=='w') (x&1?++s2:--s2);
		printf("%d\n",F());
	}
}