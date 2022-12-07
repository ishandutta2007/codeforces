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
const int mo=1000000007;
int n,m,a[121],ans;
void dfs(int d,int x,bitset<121> B,int v){
	//cout<<d<<' '<<x<<' '<<v<<endl;
	ans=(ans+v)%mo;
	//if (d==6) return;
	For(i,x,m/2) if (a[i]&&!B[i])
		dfs(d+1,i+1,B|(B<<i)|(B>>i)|(B<<(m-i))|(B>>(m-i)),1ll*v*a[i]%mo);
}
int main(){
	scanf("%*d%d%d",&m,&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		++a[min(m-x%m,x%m)];
	}
	bitset<121> B; B[0]=1;
	dfs(1,1,B,1);
	printf("%d\n",ans);
}