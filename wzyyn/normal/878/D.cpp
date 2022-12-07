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
const int N=100055,M=(1<<12);
int n,K,Q,m;
int a[13][N],S[13][N];
bitset<M> B[N];
int main(){
	scanf("%d%d%d",&n,&K,&Q); m=K;
	For(i,0,K-1) For(j,1,n) scanf("%d",&a[i][j]);
	For(i,0,K-1) For(j,0,(1<<K)-1) if (j&(1<<i)) B[i][j]=1;
	For(i,0,K-1) For(j,0,K-1) For(k,1,n)
		if (a[i][k]>=a[j][k]) S[j][k]|=1<<i;
	//cout<<S[0][2]<<' '<<S[1][2]<<endl;
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) B[m++]=B[x-1]|B[y-1];
		if (tp==2) B[m++]=B[x-1]&B[y-1];
		if (tp==3){
			int ans=0;
			For(i,0,K-1)
				if (B[x-1][S[i][y]])
					ans=max(ans,a[i][y]);
			cout<<ans<<endl;
		}
	}
}