#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
int n,m,S[100005],x;
void solve(){
	scanf("%d%d",&n,&m);
	For(i,0,m-1) S[i]=0;
	For(i,1,n) scanf("%d",&x),++S[x%m];
	int ans=0;
	if (S[0]) ++ans;
	if (m%2==0&&S[m/2]) ++ans;
	For(i,1,(m-1)/2) if (S[i]||S[m-i]) ans+=max(abs(S[i]-S[m-i]),1);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}