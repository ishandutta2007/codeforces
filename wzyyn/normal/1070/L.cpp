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
int n,m;
bitset<N> S[N];
vector<int> e[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int ans=1;
	For(i,1,n)
		if (e[i].size()&1)
			ans=2;
	printf("%d\n",ans);
	if (ans==1){
		For(i,1,n) printf("1 ");
		puts("");
		return;
	}
	For(i,1,n) For(j,0,n) S[i][j]=0;
	For(i,1,n) for (auto j:e[i]) S[i][j]=1^S[i][j];
	For(i,1,n)
		if (e[i].size()&1)
			S[i][0]=S[i][i]=1;
	For(i,1,n){
		For(j,i+1,n)
			if (S[j][i]){
				swap(S[i],S[j]);
				break;
			}
		For(j,1,n)
			if (j!=i&&S[j][i])
				S[j]^=S[i];
	}
	For(i,1,n)
		printf("%d ",(int)(S[i][0])+1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}