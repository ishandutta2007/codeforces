#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 1e5+5;
 
int T, n;
char a[N], b[N];
int to[25], fa[25];
bool dag[1<<20];

int find(int x){return x==fa[x] ? x : find(fa[x]);}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>(a+1)>>(b+1);
		rep(i,1,20) fa[i] = i, to[i] = 0;
		rep(i,1,n){
			int x = a[i]-'a'+1, y = b[i]-'a'+1;
			fa[find(x)] = find(y);
			if (x!=y) to[x] |= (1<<y-1);
		}
		int tot = 40, ans = 0;
		rep(i,1,20) tot -= (i==fa[i]);
		
		memset(dag,0,sizeof dag);
		dag[0] = 1;
		rep(mask,0,(1<<20)-1) if(dag[mask]) {
			rep(i,0,19) if(!(mask>>i&1) && ((mask&to[i+1]) == 0) )
				dag[mask|(1<<i)] = true;
			ans = max(ans, __builtin_popcount(mask));
		}
		cout<<tot-ans<<endl;
	}
	
	return 0;
}