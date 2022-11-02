#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const int N=101,mod=1000000007;
int n,m,p,f[N][N][N],g[N][N][N],c[N][N],ans;
inline void add(int &a,int b){
	a=a+b>=mod?a+b-mod:a+b;
}
signed main(){
	n=read(); m=read(); p=read();
	for(int i=0;i<=n;i++){
		c[i][0]=1; for(int j=1;j<=i;j++)c[i][j]=min(1000,c[i-1][j-1]+c[i-1][j]);
	}
	for(int i=1;i<=n;i++)f[i][i][1]=1;
	for(int i=1;i<m;i++){
		memset(g,0,sizeof(g));
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j;k++){
				for(int l=1;l<=p;l++)if(f[j][k][l]){
					//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[j][k][l]<<endl;
					for(int o=k;j+o<=n;o++)if(l*c[o-1][k-1]<=p){
						add(g[j+o][o-k][l*c[o-1][k-1]],f[j][k][l]);
					}
				}
			}
		}
		swap(f,g);
		for(int j=1;j<=n;j++)for(int l=1;l<=p;l++)ans=(ans+(ll)f[j][0][l]*(m-i))%mod;
	}
	cout<<ans<<endl;
}
/*

*/