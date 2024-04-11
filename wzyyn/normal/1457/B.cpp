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
const int N=100005;
int n,k,a[N],ans;
void solve(){
	ans=1<<30;
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,100){
		int p=1,s=0;
		for (;p<=n;)
			if (a[p]==i) ++p;
			else p+=k,s++;
		ans=min(ans,s);
	} 
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}