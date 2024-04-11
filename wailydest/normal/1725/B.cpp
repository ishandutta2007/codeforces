//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 1e5+7;
int A[N];
void solve(){
	int n,d;
	cin>>n>>d;
	d += 1;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	sort(A+1,A+1+n);
	int ptr = 0;
	int res = 0;
	for(int i = n;i>ptr;i-=1){
		int need = d/A[i] + (d%A[i]!=0)-1;
		ptr += need;
		if (ptr<i){
			res += 1;
		}
	}
	cout<<res<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}