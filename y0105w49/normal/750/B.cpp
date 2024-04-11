#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second

int main() {
	int n; cin>>n;

	int ang=10000;
	for(;n--;) {
		int t; string dir;
		cin>>t>>dir;
		if(dir[0]=='E'||dir[0]=='W') {
			if(ang==10000 || ang==-10000) goto die;
			continue;
		}
		if(dir[0]=='N') ang+=t; else
		if(dir[0]=='S') ang-=t; else
		assert(0);
		if(ang<-10000 || ang>10000) goto die;
	}
	if(ang!=10000) goto die;





	cout<<"YES\n";
	return 0;
	die:;
	cout<<"NO\n";
}