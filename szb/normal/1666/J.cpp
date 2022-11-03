#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
#define pb push_back
inline ll read()
{
	ll x = 0, f = 1;
	char ch = 0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-48;
	return x*f;	
}
const ll N=210;
ll a[N][N],fa[N],cho[N][N],f[N][N],calc[N][N],u[N][N],v[N][N],n;
void dfs(ll l,ll r,ll ff){
	if (l>r)return;
	fa[cho[l][r]]=ff;
	if (l==r)return;
	dfs(l,cho[l][r]-1,cho[l][r]);
	dfs(cho[l][r]+1,r,cho[l][r]);
}
int main(){
	n=read();
	For(i,1,n)For(j,1,n)a[i][j]=read();
	For(i,1,n)For(j,i,n){
		u[i][j]=u[i][j-1];
		For(k,1,i-1)
			u[i][j]=u[i][j]+a[k][j];
	}
	FOr(i,n,1)FOr(j,i,1){
		v[j][i]=v[j+1][i];
		For(k,i+1,n)
			v[j][i]=v[j][i]+a[j][k];
	}
	For(i,1,n)For(j,i,n)calc[i][j]=u[i][j]+v[i][j];//cout<<'*'<<i<<' '<<j<<' '<<calc[i][j]<<endl;;
	For(i,0,n+1)For(j,0,n+1)
	if(i>j)f[i][j]=f[i][j]=0;
	else if (i==j&&i>0&&i<=n)
	 				f[i][j]=calc[i][j],cho[i][j]=i;
	else	f[i][j]=1e18;
	For(len,2,n){
		For(i,1,n-len+1){
			ll j=i+len-1;
			For(k,i,j){
				ll	now=f[i][k-1]+f[k+1][j]+calc[i][j];
				if(now<f[i][j]){
					f[i][j]=now;
					cho[i][j]=k;
				}
			}
//			cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
	}
	dfs(1,n,0);
	For(i,1,n)printf("%lld ",fa[i]);puts("");
}