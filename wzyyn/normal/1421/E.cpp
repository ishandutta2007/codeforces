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
int n,x;
ll f[3][2][2];
ll g[3][2][2];
int main(){
	scanf("%d%d",&n,&x);
	if (n==1) return printf("%d\n",x),0;
	memset(f,233,sizeof(f));
	f[1][0][0]=x;
	f[2][1][0]=-x;
	For(i,2,n){
		memset(g,233,sizeof(g));
		scanf("%d",&x);
		For(S,0,2) For(la,0,1) For(ff,0,1){
			g[(S+1)%3][0][ff|(la==0)]=max(g[(S+1)%3][0][ff|(la==0)],f[S][la][ff]+x);
			g[(S+2)%3][1][ff|(la==1)]=max(g[(S+2)%3][1][ff|(la==1)],f[S][la][ff]-x);
		}
		memcpy(f,g,sizeof(f));
		//cout<<f[i%3][0][1]<<endl;
	}
	cout<<max(g[1][0][1],g[1][1][1])<<endl;
}