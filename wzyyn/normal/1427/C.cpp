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
const int N=105000;
int R,n,ans,x[N],y[N],v[N],f[N];
int main(){
	scanf("%d%d",&R,&n);
	For(i,1,n) scanf("%d%d%d",&v[i],&x[i],&y[i]);
	x[0]=y[0]=1;
	memset(f,233,sizeof(f));
	f[0]=0;
	int mx=-(1<<30);
	For(i,1,n){
		if (i>=1000) mx=max(mx,f[i-1000]);
		f[i]=mx;
		For(j,max(0,i-999),i-1)
			if (v[j]+abs(x[j]-x[i])+abs(y[j]-y[i])<=v[i])
				f[i]=max(f[i],f[j]);
		ans=max(ans,++f[i]);
		//cout<<i<<' '<<f[i]<<' '<<mx<<endl;
	}
	cout<<ans<<endl;
}