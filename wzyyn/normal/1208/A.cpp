#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;

void solve(){
	int T,x,y;
	scanf("%d%d%d",&x,&y,&T);
	if (T%3==0) printf("%d\n",x);
	else if (T%3==1) printf("%d\n",y);
	else printf("%d\n",x^y);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
a
b
a^b
a
b
*/