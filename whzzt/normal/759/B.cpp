#include"bits/stdc++.h"
#define mp make_pair
using namespace std;
const int N = 200005, oo = 1e9;
typedef map<int,int>::iterator mii;
map<int,int> ans; 
int n, t[N], dp[N];
int main(){
	//freopen("b.in","r",stdin);
	scanf ("%d",&n);
	ans.insert(mp(0,0));
	for (int i=1; i<=n; i++){
		scanf("%d",&t[i]);
		dp[i] = dp[i-1]+20;
		mii k = ans.lower_bound(t[i]-89);
		if (k!=ans.end()){
			int j = k->second;
			if (j!=0) j--;
			dp[i] = min(dp[i],dp[j]+50);
		}
		k = ans.lower_bound(t[i]-1439);
		if (k!=ans.end()){
			int j = k->second;
			if (j!=0) j--;
			dp[i] = min(dp[i],dp[j]+120);
		}
		printf ("%d\n", dp[i]-dp[i-1]);
		ans.insert(mp(t[i],i));
	}
	return 0;
}