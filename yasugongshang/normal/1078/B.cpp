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
const int N=105;
const ll mod=100000000000000007;
int n,a[N],tong[N],zs,sum;
ll dp[N][N*N],c[N][N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++){tong[a[i]=read()]++; sum+=a[i];}
	for(int i=1;i<=100;i++)if(tong[i])zs++;
	if(zs==2){
		cout<<n<<endl; return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=c[i][0]=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j;j--){
			for(int k=j*100;k>=a[i];k--){
				dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
				//if(dp[j][k])cout<<i<<" "<<j<<" "<<k<<" "<<dp[j][k]<<endl;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=tong[i];j++){
			if(dp[j][j*i]==c[tong[i]][j]||(dp[n-j][sum-j*i]==c[tong[i]][j]))ans=max(ans,j);
		}
	}
	cout<<ans<<endl;
}
/*

 
*/