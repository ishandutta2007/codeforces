#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

#define l first
#define r second
#define Pair pair<int,int>

int n , m , k , x , y;
Pair now[N];
set< Pair > in[N] , cur;
set< Pair > :: iterator all;

vector<int>ans;

int main(void) {
	scanf("%d%d" , &n , &m);
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d" , &x , &y);
		now[i] = make_pair(min(n - x + 1 , y) , max(n - x + 1 , y));
		in[now[i].l].insert(make_pair(now[i].r , i));
	}
	sort(now + 1 , now + m + 1);
	for(int i = 1;i <= n;++ i) {
		for(all = in[i].begin();all != in[i].end();++ all) cur.insert(*all);
		while((*(cur.begin())).first < i && cur.size()) cur.erase(cur.begin());
		if(!cur.size()) continue;
		ans.push_back((cur.begin()) -> second);
		cur.erase(cur.begin());
	}
	cout << ans.size() << endl;
	sort(ans.begin() , ans.end());
	for(int i = 0;i <(int) ans.size(); ++ i) cout << ans[i] <<" ";
}