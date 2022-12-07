#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

void solve(){
	int u,v;
	scanf("%d%d",&u,&v);
	if (u>v) puts("NO");
	else if (u==v) puts("YES");
	else{
		int s0=0,s1=0;
		For(i,0,29){
			if (v&(1<<i))
				if (s0-1+((u>>i)&1)<s1)
					return puts("NO"),void(0);
			s0+=(u>>i)&1;
			s1+=(v>>i)&1;
		}
		puts("YES");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}