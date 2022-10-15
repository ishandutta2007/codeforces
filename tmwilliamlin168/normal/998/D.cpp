#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mn[49], mx[49];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, ans=0;
	cin >> n;
	for(int i=0; i<49; ++i)
		mn[i]=LLONG_MAX;
	for(int i=0; i<49; ++i) {
		for(int j=0; j<49; ++j) {
			int a1=i+j, a2=5*i+10*j, b=(n-a1+a2)%49;
			if(n-a1<0)
				continue;
			mn[b]=min(n-a1+a2, mn[b]);
			mx[b]=max(50*(n-a1)+a2, mx[b]);
		}
	}
	for(int i=0; i<49; ++i)
		ans+=max((mx[i]-mn[i])/49+1, 0ll);
	cout << ans;
}