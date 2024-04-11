#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const int inf=1e9+99;
#define fi first
#define se second
#define y1 arst

int main() {
	int n; string s; cin>>n>>s;
	int i=0,j=n-1,z=0;
	for(;i<n&&s[i]=='<';) ++i,++z;
	for(;j>=0&&s[j]=='>';) --j,++z;
	cout<<z<<endl;
}