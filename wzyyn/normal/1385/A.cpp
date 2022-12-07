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

void solve(){
	int x,y,z,a,b,c;
	scanf("%d%d%d",&x,&y,&z);
	a=min(x,y),b=min(x,z),c=min(y,z);
	if (max(a,b)!=x||max(a,c)!=y||max(b,c)!=z)
		puts("NO");
	else printf("YES\n%d %d %d\n",a,b,c);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}