#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

int n;
int x[2013], y[2013];
vector<pair<int,int> > has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		if (i==j) continue;
		has.push_back(MP(x[j]-x[i],y[j]-y[i]));
	}
	sort(has.begin(),has.end());
	has.push_back(MP(0,0));
	ll ans = 0;
	for (int i=0;i<has.size()-1;i++) {
		if (has[i]!=has[i+1]) {
			int j = i;
			while (j && has[j-1]==has[i]) j-=1;
			ans+=(i-j+1)*(i-j)/2;
		}
	}
	printf("%lld\n",ans/4);

	return 0;
}