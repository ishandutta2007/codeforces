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
const int N=1005;
int n,a[N],vis[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),vis[i]=0;
	int p=1;
	For(i,2,n) if (a[i]>a[p]) p=i;
	vis[p]=1;
	printf("%d ",a[p]);
	int G=a[p];
	For(i,2,n){
		int np=-1,nv=0;
		For(j,1,n) if (!vis[j]){
			int val=gcd(G,a[j]);
			if (val>nv) nv=val,np=j;
		}
		vis[np]=1;
		printf("%d ",a[np]);
		G=gcd(G,a[np]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}