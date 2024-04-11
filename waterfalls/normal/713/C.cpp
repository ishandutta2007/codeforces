#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
map<ll,ll> slope;

int main() {
	ll y = 0;
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		int h;
		scanf("%d",&h);
		h = 1.1e9-h+i;
		slope[h]+=2;
		y+=h;
		slope[slope.begin()->first]-=1;
		y-=slope.begin()->first;
		if (slope.begin()->second==0) slope.erase(slope.begin());
	}
	printf("%lld\n",y);

	return 0;
}