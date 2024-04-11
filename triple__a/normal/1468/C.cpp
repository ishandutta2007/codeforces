#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw
 
set<pair<int, int> > SA, SB;
 
int main() {
	int id = 0;
	int q; scanf("%d", &q);

	while (q--) {
		int op; scanf("%d", &op);
		
		if (op == 1) {
			int x; scanf("%d", &x);
			
			id++;
			
			pair<int, int> A1 = mp(id, -x);
			pair<int, int> A2 = mp(-x, id);
			
			SA.insert(A1);
			SB.insert(A2);
		} else if (op == 2) {
			auto good = *(SA.begin());
			
			printf("%d ", good.first);
			SA.erase(SA.find(good));
			SB.erase(SB.find(mp(good.second, good.first)));	
		} else if (op == 3) {
			auto good = *(SB.begin());
			
			printf("%d ", good.second);
			SB.erase(SB.find(good));
			SA.erase(SA.find(mp(good.second, good.first)));	
		}
	}
	puts("");
}