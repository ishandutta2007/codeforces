#include <bits/stdc++.h>
using namespace std;

int readint() {
	char c;
	while ((c=getchar())<'0');
	int res = c-'0';
	while ((c=getchar())>='0') res = res*10+c-'0';
	return res;
}

#define MP make_pair
#define A first
#define B second

int n;
int a[2513][2513];
bitset<2513> big[2513];
vector<int> comp;
vector<pair<int,int> > need[2513*2513];

int main() {
	n = readint();
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		a[i][j] = readint();
		if (i==j && a[i][j]!=0) return printf("NOT MAGIC\n"), 0;
		if (i>j && a[i][j]!=a[j][i]) return printf("NOT MAGIC\n"), 0;
		comp.push_back(a[i][j]);
	}
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		need[lower_bound(comp.begin(),comp.end(),a[i][j])-comp.begin()].push_back(MP(i,j));
	}
	for (int i=0;i<n*n;i++) {
		auto& v = need[i];
		for (auto& p: v) {
			if ((big[p.A]&big[p.B]).any()) return printf("NOT MAGIC\n"), 0;
		}
		for (auto& p: v) big[p.A][p.B] = 1;
	}
	printf("MAGIC\n");

	return 0;
}