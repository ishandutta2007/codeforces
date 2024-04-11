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
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n,x,y,mx=0,ans=1<<30;
		scanf("%d%d",&n,&x);
		For(i,1,n) scanf("%d",&y),mx=max(mx,y),(y==x?ans=1:233);
		printf("%d\n",min(ans,max(2,x/mx+(x%mx!=0))));
	}
}