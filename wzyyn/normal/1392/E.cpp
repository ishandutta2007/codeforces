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

ll a[30][30];
ll mn[30][30];
ll mx[30][30];
int n;
int main(){
	scanf("%d",&n);
	For(j,1,n) For(i,1,n){
		mn[i][j]=1ll<<60,mx[i][j]=-(1ll<<60);
		if (i!=1){
			mn[i][j]=min(mn[i][j],mn[i-1][j]);
			mx[i][j]=max(mx[i][j],mx[i-1][j]);
		}
		if (j!=1){
			mn[i][j]=min(mn[i][j],mn[i][j-1]);
			mx[i][j]=max(mx[i][j],mx[i][j-1]);
		}
		if (i==1&&j==1) a[i][j]=mn[i][j]=mx[i][j]=0;
		else{
			double lo=mx[i+1][j-1];
			a[i][j]=lo+1-mn[i][j];
			mn[i][j]+=a[i][j];
			mx[i][j]+=a[i][j];
		}
		//cout<<i<<' '<<j<<' '<<a[i][j]<<' '<<mn[i][j]<<' '<<mx[i][j]<<endl;
	}
	For(i,1,n) For(j,1,n)
		if (i!=n&&j!=1) assert(mn[i][j]>mx[i+1][j-1]);
	For(i,1,n) For(j,1,n)
		printf("%lld%c",a[i][j],j==n?'\n':' ');
	fflush(stdout);
	int Q;
	scanf("%d",&Q);
	while (Q--){
		ll v;
		scanf("%lld",&v);
		int qx[55],qy[55];
		qx[1]=qy[1]=n;
		For(i,2,2*n-1){
			v-=a[qx[i-1]][qy[i-1]];
			//cout<<v<<' '<<qx[i-1]<<' '<<qy[i-1]<<' '<<mx[qx[i-1]-1][qy[i-1]]<<endl;
			if (qx[i-1]!=1&&v>=mn[qx[i-1]-1][qy[i-1]])
				qx[i]=qx[i-1]-1,qy[i]=qy[i-1];
			else qx[i]=qx[i-1],qy[i]=qy[i-1]-1;
		}
		Rep(i,2*n-1,1)
			printf("%d %d\n",qx[i],qy[i]);
	fflush(stdout);
	}
}