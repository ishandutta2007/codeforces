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
char s[2005];
void solve(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	For(i,1,b) s[i]=i+'a'-1;
	For(i,b+1,a) s[i]=s[i-1];
	For(i,a+1,n) s[i]=s[i-a];
	s[n+1]=0;
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}