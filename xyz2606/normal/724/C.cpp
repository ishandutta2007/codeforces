#include<bits/stdc++.h>
using namespace std;
const int N(1111111);
long long ans[N];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int d(__gcd(n, m));
	map<pair<int, int>, int> q1, q2;
	for(int i(0); i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		q1[make_pair(x + y, y)] = i;
		q2[make_pair(x - y, y)] = i;
	}
	int curx(0), cury(0);
	memset(ans, -1, sizeof(ans));
	int dx(1), dy(1);
   	long long curt(0);
	for(;;) {
		//printf("%d %d\n", curx, cury);
		int newdx, newdy;
		int deltax(dx == 1 ? n - curx : curx);
		int deltay(dy == 1 ? m - cury : cury);
		if(deltax == deltay) {
			newdx = newdy = -100;
		}else  if(deltax < deltay) {
			newdx = -dx;
			newdy = dy;
		}else {
			newdy = -dy;
			newdx = dx;
		}
		int delta(min(dx == 1 ? n - curx : curx, dy == 1 ? m - cury : cury));
		int y2(cury + delta * dy);
		int y1(cury);
		if(y1 > y2) {
			swap(y1, y2);
		}
		if(dx == dy) {
			for(;;) {
				auto itr(q2.lower_bound(make_pair(curx - cury, y1)));
				if(itr == q2.end() || itr->first.first != curx - cury || itr->first.second > y2) {
					break;
				}
				if(ans[itr->second] == -1) {
					ans[itr->second] = curt + abs(itr->first.second - cury);
				}
				q2.erase(itr);
			}
		}else {
			for(;;) {
				auto itr(q1.lower_bound(make_pair(curx + cury, y1)));
				if(itr == q1.end() || itr->first.first != curx + cury || itr->first.second > y2) {
					break;
				}
				if(ans[itr->second] == -1) {
					ans[itr->second] = curt + abs(itr->first.second - cury);
				}
				q1.erase(itr);
			}
			
		}
		curt += delta;
		if(newdx == -100) {
			break;
		}else {
			curx += delta * dx;
			cury += delta * dy;
			dx = newdx;
			dy = newdy;
			if((curx == n || curx == 0) && (cury == 0 || cury == m)) {
				break;
			}
		}
	}
	for(int i(0); i < k; i++) {
		printf("%I64d\n", ans[i]);
	}

}