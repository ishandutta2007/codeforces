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
const int N=3400,mod=1e9+7;
char A[1005];
int p,a,b[N],arr[1005],n;
int dp[N][N][2][2];
inline int get(ll x){
	return x<p?(x+1)*(x+2)/2%mod:(p*(x-p+1)+(x+2)*(p+p-x-1)/2)%mod;
}
inline void add(int &a,ll b){
	a=(a+b)%mod;
}
int main(){
	p=read(),a=read();
	scanf("%s",A);
	int len=strlen(A);
	For(i,0,len-1)arr[i]=A[len-1-i]-'0';
	while(len){
		ll t=0;
		Rep(i,len-1,0){
			t=t*10+arr[i];
			arr[i]=t/p; t%=p;
		}
		b[n++]=t;
		while(len&&!arr[len-1])len--;
	}
	const int D=(ll)p*p%mod;
	dp[0][0][0][0]=1;
	For(i,0,n-1){
		For(j,0,i){
			For(k,0,1){
				For(l,0,1){
					if(dp[i][j][k][l]){
						//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]%mod<<endl;
						ll x=dp[i][j][k][l];
						int A=get(b[i]-k-l),B=get(p-1-k),C=get(p+b[i]-k-l);
						add(dp[i+1][j][0][0],x*A);
						add(dp[i+1][j][0][1],x*(B-A+mod));
						add(dp[i+1][j+1][1][0],x*(C-B+mod));
						add(dp[i+1][j+1][1][1],x*(D-C+mod));
					}
				}
			}
		}
	}
	int ans=0;
	For(j,a,n)ans=(ans+dp[n][j][0][0])%mod;
	cout<<ans<<endl;
}