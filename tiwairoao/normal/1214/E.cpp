#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
struct node{
	int i, d;
	friend bool operator < (node a, node b) {
		return a.d > b.d;
	}
}a[MAXN + 5];
vector<int>vec;
vector<pair<int, int> >ans;
int n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i].d), a[i].i = i;
	sort(a + 1, a + n + 1);
	for(int i=1;i<=n;i++) {
		vec.push_back(2*a[i].i - 1);
		if( i != 1 )
			ans.push_back(make_pair(2*a[i].i - 1, 2*a[i - 1].i - 1));
	}
	for(int i=1;i<=n;i++) {
		ans.push_back(make_pair(2*a[i].i, vec[i + a[i].d - 2]));
		if( vec.size() - i + 1 == a[i].d )
			vec.push_back(2*a[i].i);
	}
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}