#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=51,M=50000;
bitset<M*N> dp[N][27];
int a[N],ans[2][25];
int main(){
	int n=read(),sum=0;
	For(i,0,n*2-1)a[i]=read(); sort(a,a+2*n);
	dp[2][0][0]=1;
	For(i,2,n*2-1){
		sum+=a[i];
		For(j,0,min(n-1,i)){
			dp[i+1][j]|=dp[i][j];
			dp[i+1][j+1]=dp[i][j]<<a[i];
		}
	}
	//For(i,0,sum)cout<<dp[2*n][n][i];
	For(i,(sum+1)/2,sum)if(dp[2*n][n-1][i]){//cout<<i<<endl;
		int d1=n-1,d2=i,D0=n,D1=-1;
		Rep(j,2*n-1,2){
			if(dp[j][d1][d2]){
				ans[1][++D1]=a[j];
			}else{
				ans[0][--D0]=a[j];
				d1--; d2-=a[j];
			}
		}
		break;
	}
	ans[0][0]=a[0]; ans[1][n-1]=a[1];
	For(i,0,1){
		For(j,0,n-1)wri(ans[i][j]); puts("");
	}
}