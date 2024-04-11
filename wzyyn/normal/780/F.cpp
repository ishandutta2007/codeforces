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
bitset<N> B[2][62][N],tmp;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		B[v][0][x][y]=1;
	}
	For(i,1,61){
		For(j,1,n) For(k,1,n)
			if (B[0][i-1][j][k])
				B[0][i][j]|=B[1][i-1][k];
		For(j,1,n) For(k,1,n)
			if (B[1][i-1][j][k])
				B[1][i][j]|=B[0][i-1][k];
	}
	ll ans=0,fl=0;
	For(i,1,n) tmp[i]=1;
	Rep(i,61,0){
		bitset<N> tmpp;
		For(j,1,n) tmpp[j]=0;
		For(j,1,n) if (tmp[j]) tmpp|=B[fl][i][j];
		bool fll=0;
		For(j,1,n) if (tmpp[j]) fll=1;
		if (fll) tmp=tmpp,ans+=1ll<<i,fl^=1;
	}
	cout<<(ans>1000000000000000000ll?-1:ans);
}