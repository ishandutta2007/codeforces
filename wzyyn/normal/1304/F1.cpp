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
const int N=55,M=20005;
int n,m,k;
int a[N][M],f[N][M];
struct TREE{
	int t[M*4],nn;
	void init(int n){
		for (nn=1;nn<=n+1;nn<<=1);
		For(i,1,2*nn-1) t[i]=-(1<<30);
	}
	void change(int x,int y,int v){
		x+=nn-1; y+=nn+1;
		for (;x^y^1;x>>=1,y>>=1){
			if (!(x&1)) t[x^1]=max(t[x^1],v);
			if (y&1)	t[y^1]=max(t[y^1],v);
		}
	}
	int ask(int x){
		int ans=-(1<<30); x+=nn;
		for (;x;x>>=1) ans=max(ans,t[x]);
		return ans;
	}
}TR1,TR2,TR3;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m) a[i][j]+=a[i][j-1];
	For(i,1,m-k+1) f[1][i]=a[1][i+k-1]-a[1][i-1];
	For(i,2,n){
		For(j,1,m-k+1) f[i-1][j]+=a[i][j+k-1]-a[i][j-1];
		TR1.init(m); TR2.init(m); TR3.init(m);
		For(j,1,m-k+1){
			if (j-k>=1) TR1.change(1,j-k,f[i-1][j]);
			if (j+k<=m-k+1) TR1.change(j+k,m-k+1,f[i-1][j]);
			TR2.change(max(j-k,1),j,f[i-1][j]+a[i][j-1]);
			TR3.change(j,min(m-k+1,j+k),f[i-1][j]-a[i][j+k-1]);	
		}
		For(j,1,m-k+1){
			f[i][j]=TR1.ask(j)+a[i][j+k-1]-a[i][j-1];
			f[i][j]=max(f[i][j],TR2.ask(j)-a[i][j-1]);
			f[i][j]=max(f[i][j],TR3.ask(j)+a[i][j+k-1]);
			///cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<TR1.ask(j)+a[i][j+k-1]-a[i][j-1]<<' '<<TR3.ask(j)<<endl;
		}
	}
	int ans=0;
	For(i,1,m-k+1){
		//cout<<f[n][i]<<endl;
		ans=max(ans,f[n][i]);
	}
	printf("%d\n",ans);
}