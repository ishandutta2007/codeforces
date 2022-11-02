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
const int N=85,inf=1e9;
pair<int,int> e[N][N][N];
int mn=1e9,A[10],n,k,to[N],a[N][N];
int dis(int x,int y){
	For(i,1,n)if(!to[e[x][y][i].se])return e[x][y][i].fi;
	return 2e8;
}
void dfs(int p){
	if(p*2>=k){
		int ans=0;
		For(i,0,p-1){
			ans+=dis(A[i],A[(i+1)%p]);
		}
		//if(ans==1)cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<ans<<" "<<to[2]<<" "<<dis(1,2)<<" "<<dis(2,4)<<" "<<dis(4,2)<<" "<<dis(2,1)<<endl;
		mn=min(mn,ans);
		return;
	}
	For(i,1,n){
		A[p]=i; to[i]++;
		dfs(p+1);
		to[i]--;
	}
}
int main(){
	n=read(),k=read();
	For(i,1,n)For(j,1,n)a[i][j]=read();
	For(i,1,n)For(j,1,n){
		For(k,1,n)if(k==i||k==j){
			e[i][j][k]=mp(inf,k);
		}else e[i][j][k]=mp(a[i][k]+a[k][j],k);
		sort(e[i][j]+1,e[i][j]+n+1);	
	}
	A[0]=to[1]=1;
	dfs(1);
	cout<<mn<<endl;
}