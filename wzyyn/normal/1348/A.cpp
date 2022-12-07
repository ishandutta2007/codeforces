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
	int n;
	scanf("%d",&n);
	int s1=0,s2=0;
	For(i,1,n/2-1) s1+=1<<i;
	For(i,n/2,n-1) s2+=1<<i;
	s1+=1<<n;
	printf("%d\n",s1-s2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}