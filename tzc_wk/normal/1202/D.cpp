#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define int long long
vector<int> ans;
signed main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		ans.clear();
		putchar('1');
		for(int i=50005;i>=1;i--){
			while(n>=(i*(i+1)/2)){
				ans.push_back(i+1);
				n-=i*(i+1)/2;
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=1;i<=ans[0];i++)	putchar('3');putchar('7');
		for(int i=1;i<ans.size();i++){
			for(int j=1;j<=ans[i]-ans[i-1];j++)
				putchar('3');
			putchar('7');
		}
		cout<<endl;
	}
}