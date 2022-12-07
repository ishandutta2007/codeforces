#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,d,e,ans;
int main(){
	scanf("%d%d%d",&n,&d,&e);
	ans=1<<30;
	For(i,0,10000) if (d*i<=n)
		ans=min(ans,(n-d*i)%(5*e));
	printf("%d\n",ans);
}