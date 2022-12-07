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
	int n,x,y,ans=1<<30,dx,dy;
	scanf("%d%d%d",&n,&x,&y);
	For(d,1,n-1)
		if ((y-x)%d==0){
			int dd=(y-x)/d;
			int fi=y-(n-1)*dd;
			for (;fi<=0;fi+=dd);
			if (fi+(n-1)*dd<ans)
				ans=fi+(n-1)*dd,dx=fi,dy=dd;
		}
	For(i,1,n) cout<<dx+(i-1)*dy<<' ';
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}