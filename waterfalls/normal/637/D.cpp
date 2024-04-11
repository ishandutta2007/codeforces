#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m,s,d;
int a[200013];
vector<pair<string,int> > ans;

int main() {
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = -1;
	a[++n] = m+s+2;
	a[++n] = 2e9;
	sort(a,a+n);
	int cur = 0;
	int far = 0;
	int best = 0;
	while (true) {
		if (a[cur+1]-a[cur]-2<s) return printf("IMPOSSIBLE\n"), 0;
		ans.push_back(MP("RUN",a[cur+1]-a[cur]-2));
		if (a[cur+1]-1>=m) {
			ans.back().B = m-a[cur]-1;
			break;
		}
		while (a[far+1]+1<=a[cur+1]-1+d) {
			far++;
			if (a[far+1]-a[far]-2>=s) best = far;
		}
		if (best<=cur) return printf("IMPOSSIBLE\n"), 0;
		ans.push_back(MP("JUMP",a[best]-a[cur+1]+2));
		if (a[best]+1>=m) {
			ans.back().B = m-a[cur+1]+1;
			break;
		}
		cur = best;
	}
	for (auto p: ans) printf("%s %d\n",p.A.c_str(),p.B);

	return 0;
}