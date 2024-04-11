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
#define mem(a) memset((a),0,sizeof(a))
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
const int N=5005,M=100005;
int x[M],y[M],ans[M],len[M],dir[M],op[M];
int n,m;
#define lowbit(i) i&-i
struct bit{
	int c[N<<1];
	void cle(){mem(c);}
	void change(int x){
		for(int i=x;i<=2*n;i+=lowbit(i))c[i]++;
	}
	int get(int x){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))ans+=c[i];
		return ans;
	}
}T2;
struct bibit{
	int c[N<<1][N];
	void cle(){mem(c);}
	void change(int x,int y){
		for(int i=x;i<=2*n;i+=lowbit(i))for(int j=y;j<=n;j+=lowbit(j))c[i][j]++;
	}
	int get(int x,int y){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))for(int j=y;j;j-=lowbit(j))ans+=c[i][j];
		return ans;
	}
}T3,T4;
struct bi1t{
	int c[N][N];
	void cle(){mem(c);}
	void change(int x,int y){
		for(int i=x;i<=n;i+=lowbit(i))for(int j=y;j<=n;j+=lowbit(j))c[i][j]++;
	}
	int get(int x,int y){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))for(int j=y;j;j-=lowbit(j))ans+=c[i][j];
		return ans;
	}
}T1;
void solve(int zyy){
	T1.cle(); T2.cle(); T3.cle(); T4.cle();
	For(i,1,m)if(op[i]==1){
		if(dir[i]!=zyy)continue;
		T1.change(x[i],y[i]); T2.change(x[i]+y[i]+len[i]);
		T3.change(x[i]+y[i]+len[i],n-y[i]+1); T4.change(x[i]+y[i]+len[i],n-x[i]+1);
	}else{
		//cout<<T1.get(x[i],y[i])<<" "<<T2.get(x[i]+y[i])<<endl;
		ans[i]+=T1.get(x[i],y[i])-T2.get(x[i]+y[i])+T3.get(x[i]+y[i],n-y[i])+T4.get(x[i]+y[i],n-x[i]);
	}
}
int main(){
	n=read(),m=read();
	For(i,1,m){
		op[i]=read();
		if(op[i]==1){
			dir[i]=read(); x[i]=read(); y[i]=read(); len[i]=read()+1;
		}else{
			x[i]=read(); y[i]=read();
		}
	}
	solve(1);
	//For(i,1,m)if(op[i]==2)writeln(ans[i]); return 0;
	For(i,1,m)y[i]=n-y[i]+1;
	solve(2);
	For(i,1,m)x[i]=n-x[i]+1;
	solve(4);
	For(i,1,m)y[i]=n-y[i]+1;
	solve(3);
	For(i,1,m)if(op[i]==2)writeln(ans[i]);
}