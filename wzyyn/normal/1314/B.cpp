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
const int N=17;
int f[N+1][1<<N][2][2];
int vis[1<<N],n,k;
void UPD(int &x,int y){
	x<y?x=y:233;
}
void solve(int x,int d){
	//cout<<x<<' '<<d<<endl;
	if (d==0){
		f[d][x][vis[x]][0]=0;
		return;
	}
	int y=x+(1<<(d-1));
	solve(x,d-1); solve(y,d-1);
	For(fl1,0,1) For(fl2,0,1) For(fl3,0,1) For(fl4,0,1)
		UPD(f[d][x][fl1][fl2|fl3|fl4],f[d-1][x][fl1][fl2]+f[d-1][y][fl3][fl4]+(fl1|fl3)+(fl2|fl4)+(d==1?0:fl2|fl3|fl4)),
		UPD(f[d][x][fl3][fl2|fl1|fl4],f[d-1][x][fl1][fl2]+f[d-1][y][fl3][fl4]+(fl1|fl3)+(fl2|fl4)+(d==1?0:fl2|fl1|fl4));
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,k){
		int x;
		scanf("%d",&x);
		vis[x-1]=1;
	}
	memset(f,233,sizeof(f));
	solve(0,n);
	int ans=-(1<<30);
	For(i,0,1) For(j,0,1)
		UPD(ans,f[n][0][i][j]+(i|j));
	printf("%d\n",ans);
}