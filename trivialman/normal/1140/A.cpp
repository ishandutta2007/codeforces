#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 10010;

int a[N],n;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;){
		int last=a[i], j;
		for(j=i;j<=last;++j)last=max(last,a[j]);
		++ans;i=j;
	}
	cout<<ans<<endl;
	return 0;
}