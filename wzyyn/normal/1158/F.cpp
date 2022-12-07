#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=998244353;
const int N=3005;
int n,c,a[N];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
namespace solver1{
	ll f[N][(1<<12)+5];
	void solve(){
		f[0][0]=1;
		int L=(1<<c)-1;
		int S=0,ST=0;
		For(i,1,n){
			int sta=1<<(a[i]-1);
			For(j,0,S) Rep(k,L,0) f[j][k|sta]+=f[j][k];
			For(j,0,S) f[j+1][0]+=f[j][L],f[j][L]=0;
			ST|=sta;
			if (ST==L) ST=0,S++;
			if (i%18==0||i==n)
				For(j,0,S) For(k,0,L) f[j][k]%=mo;
		}
		For(i,0,n/c){
			int ans=0;
			For(j,0,L) UPD(ans,f[i][j]);
			if (i==0) UPD(ans,mo-1);
			printf("%d ",ans);
		}
		For(i,n/c+1,n)
			printf("%d ",0);
	}
}
namespace solver2{
	int power(int x,int y){
		int s=1;
		for (;y;y/=2,x=1ll*x*x%mo)
			if (y&1) s=1ll*s*x%mo;
		return s;
	} 
	int V[N],IV[N],tr2[N];
	int cnt[N],tr1[N][N];
	ll f[N][N];
	void solve(){
		For(i,0,n){
			V[i]=power(2,i)-1;
			IV[i]=power(V[i],mo-2);
		}
		For(i,1,n){
			For(j,1,c) cnt[j]=0;
			int GG=c,val=1;
			For(j,i,n){
				if (!cnt[a[j]]) --GG;
				else val=1ll*val*IV[cnt[a[j]]]%mo;
				tr1[i][j]=(GG?0:val);
				val=1ll*val*V[++cnt[a[j]]]%mo;
			}
			tr2[i]=power(2,n-i+1);
			UPD(tr2[i],mo-(GG?0:val));
		}
		f[0][0]=tr2[n+1]=1;
		For(i,0,n/c) For(j,i*c+c,n){
			ull tmp=0;
			For(k,i*c,j-c){
				tmp+=1ll*f[i][k]*tr1[k+1][j];
				if ((k&15)==15) tmp%=mo;
			}
			f[i+1][j]=tmp%mo;
		} 
		For(i,0,n/c){
			int ans=0;
			For(j,0,n) UPD(ans,1ll*f[i][j]*tr2[j+1]%mo);
			if (i==0) UPD(ans,mo-1);
			printf("%d ",ans);
		}
		For(i,n/c+1,n) printf("%d ",0);
	}
}
int main(){
	scanf("%d%d",&n,&c);
	For(i,1,n) scanf("%d",&a[i]);
	if (c<=11) solver1::solve();
	else solver2::solve();
}