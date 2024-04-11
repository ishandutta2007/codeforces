#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second

int main() {
	int n,k; cin>>n>>k;
	int t=240;
	t-=k;
	int ans=0;
	for(int i=1;i<=n;i++) if(t>=i*5) t-=i*5, ++ans;
	cout<<ans<<endl;
}