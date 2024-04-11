#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1<<17|2,mod=998244353;
int sum,A[N],B[N],C[N],f[N];
ll ksm(ll a,int b){
	a%=mod;
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void FWT(int *a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++)if(j>>i&1){
			int x=a[j];
			a[j]=a[j^(1<<i)]>=x?a[j^(1<<i)]-x:a[j^(1<<i)]-x+mod;
			a[j^(1<<i)]=a[j^(1<<i)]+x>=mod?a[j^(1<<i)]+x-mod:a[j^(1<<i)]+x;
		}
	}
}
void ba(int &a){
	if(a>mod/2)a=a-mod;
}
signed main(){
	int n=read(),k=read();
	int x=read(),y=read(),z=read();
	for(int i=0;i<n;i++){
		int a=read(),b=read()^a,c=read()^a;
		sum^=a;
		A[b]++; B[c]++; C[b^c]++;
	}
	FWT(A,k); FWT(B,k); FWT(C,k);
	for(int i=0;i<(1<<k);i++){
		int t1=n,t2=A[i],t3=B[i],t4=C[i];
		ba(t2); ba(t3); ba(t4);
		//cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
		f[i]=ksm((ll)x+y+z,(t1+t2+t3+t4)/4)
		*ksm((ll)x+y-z,(t1+t2-t3-t4)/4)%mod
		*ksm((ll)x-y+z,(t1-t2+t3-t4)/4)%mod
		*ksm((ll)x-y-z,(t1-t2-t3+t4)/4)%mod;
		f[i]=(f[i]+mod)%mod;
	}
	FWT(f,k);
	ll in=ksm(1<<k,mod-2);
	for(int i=0;i<(1<<k);i++)f[i]=f[i]*in%mod;
	for(int i=0;i<(1<<k);i++){
		wri(f[i^sum]);
	}
}
/*
x+y+z+w=n
x+y-z-w=
x-y+z-w=
x-y-z+w=
*/