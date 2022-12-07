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
int n,m,pr[N];
char s[N];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	ll ans=n*m-n;
	For(i,2,n) if (s[i]!=s[i-1]) ans+=n*m-n;
	For(i,2,n) pr[i]=(i<=2||s[i-2]!=s[i]?i:pr[i-2]);
	For(i,2,n) if (s[i]!=s[i-1])
		ans-=i-max(pr[i],pr[i-1])+1;
	printf("%lld\n",ans);
}
/*
aba
bab
*/