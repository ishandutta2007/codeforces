#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int mo=1000000007;
const int N=55;
int fac[N],C[N][N],tr[N][N];
int n,p[N],vis[N],tab[N];
int prod[N],sz[N*N*N];
int f[N*N*N];
void init(){
	fac[0]=1;
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,1,N-1) For(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	For(i,0,n-1){
		tr[i][0]=1;
		For(j,0,i) tr[i][1]=(tr[i][1]+1ll*C[i][j]*fac[j]%mo*fac[n-j-1])%mo;
		For(j,2,N-1) tr[i][j]=1ll*tr[i][j-1]*tr[i][1]%mo;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) if (!vis[i]){
		int x=i,s=0;
		for (;!vis[x];vis[x]=1,x=p[x],++s);
		++tab[s];
	}
	init();
	prod[0]=f[0]=1;
	For(i,1,n) prod[i]=prod[i-1]*(tab[i]+1);
	For(S,0,prod[n]-1){
		static int q[N*N*N],w[N*N*N];
		int t=1;
		q[1]=0; w[1]=mo-1;
		For(i,1,n){
			int tmp=t;
			int v=(S/prod[i-1])%(tab[i]+1);
			sz[S]+=i*v;
			For(j,1,v) For(h,1,tmp){
				q[++t]=q[h]+j*prod[i-1];
				w[t]=1ll*w[h]*(j&1?mo-1:1)%mo*C[v][j]%mo;
			}
		}
		int ans=0;
		For(i,2,t) f[S]=(f[S]+1ll*f[S-q[i]]*w[i]%mo*tr[sz[S]-sz[q[i]]][sz[q[i]]])%mo;
	}
	cout<<f[prod[n]-1]<<endl;
}