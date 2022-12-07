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
#define N 5005
int n,a[N];
int f[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) a[i]+=a[i-1];
	memset(f,233,sizeof(f));
	For(i,1,n) f[i][1]=1;
	For(i,1,n){
		int p1=i,p2=i+1,v=-(1<<30);
		for (;p2<=n;++p2){
			for (;p1&&a[p2]-a[i]>=a[i]-a[p1-1];--p1)
				v=max(v,f[i][p1]);
			//cout<<i<<' '<<p1<<' '<<p2<<' '<<v<<endl;
			f[p2][i+1]=max(f[p2][i+1],v+1);
		}
	}
	int ans=0;
	For(i,0,n) ans=max(ans,f[n][i]);
	printf("%d\n",n-ans);
}