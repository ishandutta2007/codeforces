#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,m,a[15][2005];
int id[2005],mx[2005];
int f[15][4100],val[15];
int tmp[4100];
bool cmp(int x,int y){
	return mx[x]>mx[y];
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(j,1,m){
		id[j]=j,mx[j]=0;
		For(i,1,n) mx[j]=max(mx[j],a[i][j]);
	}
	sort(id+1,id+m+1,cmp);
	memset(f,0,sizeof(f));
	For(i,1,min(n,m)){
		int y=id[i];
		//printf("%d\n",y);
		For(j,1,n){
			For(k,0,n-1) val[k]=a[(j+k-1)%n+1][y];
			For(k,0,(1<<n)-1) tmp[k]=f[i-1][k];
			For(k,0,n-1) For(l,0,(1<<n)-1)
				if (l&(1<<k)) tmp[l]=max(tmp[l],tmp[l^(1<<k)]+val[k]);
			For(k,0,(1<<n)-1) f[i][k]=max(f[i][k],tmp[k]);
		}
	}
	printf("%d\n",f[min(n,m)][(1<<n)-1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}