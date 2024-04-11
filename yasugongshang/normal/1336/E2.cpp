#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
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
const int K=55,mod=998244353;
ll sum=1,a[K],b[K],ans[K],an[K],dp[K][K];
int m,cnt,ycl[1<<18|3];
void ins(ll x){
	Rep(i,m-1,0)if(x>>i&1){
		if(a[i]){
			x^=a[i];
		}else{
			a[i]=x; return;
		}
	}
	sum=sum*2%mod;
}
inline int cont(ll x){
	return x?cont(x>>18)+ycl[x&((1<<18)-1)]:0;
}
void dfs(int p,ll dq){
	if(p==cnt){
		ans[__builtin_popcountll(dq)]++; return;
	}
	dfs(p+1,dq^b[p]);
	dfs(p+1,dq);
}
int main(){
	For(i,1,(1<<18)-1)ycl[i]=ycl[i>>1]+(i&1);
	int n=read(); m=read();
	For(i,1,n){
		ins(read());
	}
	For(i,0,m-1){
		Rep(j,i-1,0)if((a[i]>>j&1)&&a[j])a[i]^=a[j];
	}
	For(i,0,m-1)if(a[i]){
		b[cnt++]=a[i];
	}
	if(cnt<=m/2){
		dfs(0,0);
	}else{
		cnt=0;
		For(i,0,m-1)if(!a[i]){
			ll x=(ll)1<<i;
			For(j,i+1,m-1)if(a[j]>>i&1)x^=(ll)1<<j;
			b[cnt++]=x;
		}else sum=sum*2%mod; 
		dfs(0,0); 
		For(i,0,m){
			mem(dp);
			dp[0][0]=1;
			For(j,0,m-1){
				For(k,0,m-1){
					dp[j+1][k]+=dp[j][k];
					dp[j+1][k+1]+=(j<i?-1:1)*dp[j][k];
				}
			}
			For(j,0,m){
				an[j]=(an[j]+dp[m][j]%mod*ans[i])%mod;
			}
		}
		For(i,1,m)sum=sum*(mod+1)/2%mod;
		swap(an,ans);
	}
	For(i,0,m){
		wri((ans[i]%mod+mod)*sum%mod);
	}
}