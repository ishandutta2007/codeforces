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
const int N=2005,mod=1e9+7;
int Row[N][N],Col[N][N],sc[N][N],sr[N][N];
ll row[N][N],col[N][N];
char ch[N][N];
int main(){
	int n=read(),m=read();
	For(i,1,n)scanf("%s",ch[i]+1);
	Rep(i,n,1)Rep(j,m,1){
		int x=ch[i][j]=='R';
		sr[i][j]=sr[i][j+1]+x;
		sc[i][j]=sc[i+1][j]+x;
	}
	For(i,1,n)Row[i][0]=1; For(j,1,m)Col[0][j]=1;
	//col[1][0]=row[0][1]=1;
	For(i,1,n){
		For(j,1,m){
			Row[i][j]=Row[i][j-1]; 
			while(sr[i][Row[i][j]+1]>m-j)Row[i][j]++;
			row[i][j]=(row[i-1][j]+col[i][j-1]-col[i][Row[i][j]-1]+mod)%mod;
			Col[i][j]=Col[i-1][j];
			while(sc[Col[i][j]+1][j]>n-i)Col[i][j]++;
			col[i][j]=(col[i][j-1]+row[i-1][j]-row[Col[i][j]-1][j]+mod)%mod;
			if(i==1&&j==1){col[i][j]++; row[i][j]++;}
			//cout<<row[i][j]<<" "<<col[i][j]<<" "<<Row[i][j]<<" "<<Col[i][j]<<" "<<col[i][j-1]<<" "<<i<<" "<<j<<endl;
		}//puts("");
	}
	if(n==1&&m==1)cout<<1<<endl;
	else cout<<(row[n][m]-row[n-1][m]+col[n][m]-col[n][m-1]+mod*2)%mod<<endl;
}