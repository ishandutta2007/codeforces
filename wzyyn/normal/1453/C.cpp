#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

const int N=2005;
char s[N][N];
int v,mnx[N],mxx[N],mny[N],mxy[N];
void solve(){
	int n;
	scanf("%d",&n);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,0,9){
		int ans=0;
		int mxx=0,mxy=0;
		int mnx=n+1,mny=n+1;
		For(j,1,n) For(k,1,n) if (s[j][k]=='0'+i){
			mxx=max(mxx,k);
			mxy=max(mxy,j);
			mnx=min(mnx,k);
			mny=min(mny,j);
		}
		For(j,1,n) For(k,1,n)
			if (s[j][k]=='0'+i){
				ans=max(ans,max(k-1,n-k)*max(j-mny,mxy-j));
				ans=max(ans,max(j-1,n-j)*max(k-mnx,mxx-k));
			}
		cout<<ans<<' ';
	}
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}