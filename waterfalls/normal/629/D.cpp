#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map<ll,ll> coast;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int r,h;
		scanf("%d%d",&r,&h);
		ll vol = 1LL*r*r*h;
		auto it = coast.lower_bound(vol);
		if (it==coast.begin()) coast[vol] = max(coast[vol],vol);
		else {
			--it;
			coast[vol] = it->second+vol;
			for (++it,++it;it!=coast.end() && it->second<=coast[vol];it=coast.erase(it));
		}
	}
	printf("%1.9f\n",2*acos(0.0)*(--coast.end())->second);


    return 0;
}