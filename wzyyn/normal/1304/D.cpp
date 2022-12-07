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
const int N=200005;
int n,ans[N];
char s[N];
void solve(){
	scanf("%d%s",&n,s+1);
	int p=1,at=n;
	For(i,1,n) if (s[i]=='>'||i==n){
		Rep(j,i,p) ans[j]=at--;
		p=i+1;
	}
	For(i,1,n) printf("%d ",ans[i]); puts("");
	p=1; at=1;
	For(i,1,n) if (s[i]=='<'||i==n){
		Rep(j,i,p) ans[j]=at++;
		p=i+1;
	}
	For(i,1,n) printf("%d ",ans[i]); puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}