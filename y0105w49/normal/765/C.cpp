#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<int> pt;
const int inf=1e9+99;
#define fi first
#define se second

int main() {
	int k,a,b; cin>>k>>a>>b;
	if(a>=k && b>=k) return cout<<a/k+b/k<<endl,0;
	if(a==0 && b==0) return cout<<0<<endl,0;
	if(a>=k && b<k && a%k==0) return cout<<a/k<<endl,0;
	if(b>=k && a<k && b%k==0) return cout<<b/k<<endl,0;
	cout<<-1<<endl;
}