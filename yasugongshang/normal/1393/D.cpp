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
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=2005,K=11;
int n,m,f[N][N],qj;
char ch[N][N],qq;
inline bool check(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m&&f[x][y]>=qj&&ch[x][y]==qq;
}
bool check(int i,int j,int len){
	qq=ch[i][j];
	return check(i-len,j)&&check(i,j-len)&&check(i+len,j)&&check(i,j+len);
}
int ans;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read(); m=read();
	For(i,1,n)scanf("%s",ch[i]+1);
	For(i,1,n)For(j,1,m)f[i][j]=1;
	For(i,1,K-1){
		int len=1<<(i-1); qj=len;
		For(i,1,n)For(j,1,m)if(f[i][j]>=len){
			if(check(i,j,len)&&check(i,j,len-1))f[i][j]=len<<1;
		}
	}
	For(i,1,n){
		For(j,1,m){
			qj=f[i][j]; int sum=0;
			Rep(o,K-1,0)if((1<<o)<f[i][j]){
				
				if(check(i,j,sum+(1<<o))){
					f[i][j]+=1<<o; sum+=1<<o;
				}
			}
			//cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
			ans+=f[i][j];
		}
	}
	cout<<ans<<endl;
}