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
const int N=2005;
int n,m,a[N*N],b[N*N];
bitset<N*2> f[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d",&a[i],&b[i]);
	For(i,1,m) f[a[i]][b[i]]=1;
	For(i,1,n) f[i][i+n]=1;
	For(i,1,n){
		For(j,i,n) if (f[j][i]){
			swap(f[i],f[j]);
			break;
		}
		For(j,1,n) if (f[j][i]&&j!=i) f[j]^=f[i];
	}
	For(i,1,m) puts(!f[b[i]][a[i]+n]?"YES":"NO");
}