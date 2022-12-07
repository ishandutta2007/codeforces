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
int tab[30];
void solve(){
	memset(tab,0,sizeof(tab));
	int n;
	scanf("%d",&n);
	For(i,1,n){
		string s;
		cin>>s;
		for (auto j:s)
			++tab[j-'a'];
	}
	For(i,0,25)
		if (tab[i]%n)
			return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}