#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

void solve(){
	int n,x;
	ll s1=0,s2=0;
	scanf("%d%d",&n,&x);
	while (n--){
		int y;
		scanf("%d",&y);
		s1+=y; s2+=(y+x-1)/x;
	}
	printf("%lld %lld\n",(s1+x-1)/x,s2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}