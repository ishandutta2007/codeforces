#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int mod=998244353,N=1000005;
ll fac[N],ni[N];
int S[N],T[N];
char s[N];
int sum,dq,ans;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll c(int a,int b){
	return a>=b&&b>=0?fac[a]*ni[b]%mod*ni[a-b]%mod:0;
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n)sum+=s[i]=='?';
	For(i,fac[0]=1,n)fac[i]=fac[i-1]*i%mod; ni[n]=ksm(fac[n],mod-2);
	Rep(i,n,1)ni[i-1]=ni[i]*i%mod;
	For(i,1,n)S[i]=S[i-1]+(s[i]=='(');
	Rep(i,n,1)T[i]=T[i+1]+(s[i]==')');
	For(i,0,n){
		if(i){
			dq+=s[i]=='?';
		}
		int A=dq,B=sum-dq,he=B+T[i+1]-S[i];
		ans=(ans+c(sum,he)*S[i]+c(sum-1,he-1)*dq)%mod;
	}
	cout<<ans<<endl;
}