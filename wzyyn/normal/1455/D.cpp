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

const int N=505;
int f[N][N];
int n,a[N];

void solve(){
	scanf("%d%d",&n,&a[0]);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,0,n+1) For(j,0,n+1) f[i][j]=1<<30;
	f[0][0]=0;
	int ans=1<<30;
	For(i,0,n) For(j,0,i) if (f[i][j]<=505){
		int v=a[j];
		//cout<<i<<' '<<j<<' '
		For(k,i+1,n){
			if (a[k]>a[i]&&(a[i]>=v)) f[k][i]=min(f[k][i],f[i][j]+1);
			if (a[k]>=v) v=a[k];
			else if (k!=1) break;
			else v=a[k];
			if (k==n)
				ans=min(ans,f[i][j]);
		}
	}
	if (ans==1<<30) ans=-1;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}