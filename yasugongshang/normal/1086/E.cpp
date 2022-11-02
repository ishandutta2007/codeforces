#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
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
const int N=2005,mod=998244353;
int n,ans,zs[N],tt[N],dq,a[N][N],tong[N];
ll f[N][N],alb[N];
#define lowbit(i) i&-i
struct BIT{
	int c[N];
	inline void change(int pos){
		for(register int i=pos;i<=n;i+=lowbit(i))c[i]--;
	}
	inline int ask(int pos){
		int ans=0; for(register int i=pos;i;i-=lowbit(i))ans+=c[i]; return ans;
	}
}T[2];
void update(int id,int pos){
	if(id==0)T[0].change(pos);
	else if(zs[pos]){
		T[1].change(pos); zs[pos]=0;
	}
}
void bao(){
	for(int i=1;i<=n;i++){tong[i]=0; tt[i]=zs[i]=1;} dq=0;
	for(int i=1;i<=n;i++)T[0].c[i]=T[1].c[i]=lowbit(i);
}
ll get(int x,int y){
	if(x<y||y<0)return 0;
	return f[y][x-y];
}
int main(){
	n=read();
	for(int i=0;i<=n;i++){// 
		f[i][0]=i?f[i-1][0]*i%mod:1;
		for(int j=1;i+j<=n;j++){
			f[i][j]=f[i][j-1]*(j-1)%mod;
			if(j>=2)f[i][j]=(f[i][j]+f[i][j-2]*(j-1))%mod;
			if(i)f[i][j]=(f[i][j]+i*f[i-1][j-1])%mod;
			if(i)f[i][j]=(f[i][j]+i*f[i-1][j])%mod;
		}
	}
	for(int i=alb[0]=1;i<=n;i++)alb[i]=alb[i-1]*f[0][n]%mod;
	for(int i=1;i<=n;i++){
		bao();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			ll sum=0;
			if(i==1){
				sum+=T[0].ask(a[i][j]-1)*f[n-j][0]; update(0,a[i][j]);
			}else{
				if(tt[a[i-1][j]]==0)dq--; else tt[a[i-1][j]]=0;
				update(1,a[i-1][j]);
				int x=T[0].ask(a[i][j]-1),y=T[1].ask(a[i][j]-1);
				sum+=(y*get(n-j,dq+1)+(x-y-(!tong[a[i-1][j]]&&(a[i-1][j]<a[i][j])))*get(n-j,dq));
				//if(i==2)cout<<ans<<" "<<x<<" fjzzq "<<y<<" "<<n-j<<" "<<dq+1<<" "<<get(n-j,dq+1)<<" "<<y*get(n-j,dq+1)*alb[n-i]<<endl;
				update(1,a[i][j]); update(0,a[i][j]);
				tong[a[i][j]]=1; if(tt[a[i][j]]){dq++; tt[a[i][j]]=0;} 
			}
			ans=(ans+sum%mod*alb[n-i])%mod;
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
/*
3
3 2 1
2 3 1
1 2 3

ij

f[i][j]ij
1
221..
331...f[i+1][j-1] 
*/