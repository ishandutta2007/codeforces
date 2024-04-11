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
int n,q[505];
char s[505];
void solve(){
	scanf("%s",s+1);
	int v=*q=0;
	for (int i=1;s[i];++i)
		if (s[i]=='1') ++v;
		else q[++*q]=v,v=0;
	q[++*q]=v;
	sort(q+1,q+*q+1,greater<int>());
	int ans=0;
	For(i,1,*q)
		if (i&1) ans+=q[i];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}