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
const int N=8005;
int n,ans,a[N],s[N];
void solve(){
	ans=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) s[i]=s[i-1]+a[i];
	For(i,1,n){
		int p1=1,p2=1;
		for (;;p1++){
			p2=max(p2,p1+1);
			for (;p2<=n&&s[p2]-s[p1-1]<a[i];++p2);
			if (p2>n) break;
			if (s[p2]-s[p1-1]==a[i]){
				++ans;
				break;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}