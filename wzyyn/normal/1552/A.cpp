#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=45;
int n;
char s[N],t[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) t[i]=s[i];
	sort(t+1,t+n+1);
	int ans=0;
	for (int i=1;i<=n;i++) ans+=(s[i]!=t[i]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}