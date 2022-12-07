#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=998244353;
const int N=55;
int n,l[N],r[N],q[N*2];
int f[N][N*2][N],ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&l[i],&r[i]);
	For(i,1,n) q[++*q]=l[i],q[++*q]=r[i]+1;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	//cout<<q[1]<<' '<<q[2]<<endl;
	For(i,1,n){
		l[i]=lower_bound(q+1,q+*q+1,l[i])-q;
		r[i]=lower_bound(q+1,q+*q+1,r[i]+1)-q-1;
		//cout<<l[i]<<' '<<r[i]<<endl;
	}
	For(i,l[1],r[1]) f[1][i][1]=q[i+1]-q[i];
	For(i,2,n) For(j,l[i-1],r[i-1]) For(k,1,i-1) For(p,l[i],min(j,r[i])){
		int nk=(p==j?k+1:1);
		f[i][p][nk]=(f[i][p][nk]+1ll*f[i-1][j][k]*(q[p+1]-q[p]+nk-1)%mo*power(nk,mo-2))%mo;
	}
	For(i,l[n],r[n]) For(j,1,n) ans=(ans+f[n][i][j])%mo;
	//cout<<ans<<endl;
	For(i,1,n) ans=1ll*ans*power(q[r[i]+1]-q[l[i]],mo-2)%mo;
	printf("%d\n",ans);
}