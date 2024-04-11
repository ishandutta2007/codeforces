#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int N = 100005;

char s[N];
int n  , m , ans;

vector<int>P , star;

bool pd(int x) {
	int it = 0;
	for(int i = 0;i < (int) P.size();i ++) {
		if(it == (int)star.size()) return 1;
		int xx = abs(P[i] - star[it]);
		if(P[i] > star[it]) {
			if(xx > x) {
				return 0;
			}
			int dis = x - xx;
			int k;
			for(k = it;k <= (int)star.size() - 1;k ++) {
				if(star[k] < P[i]) continue;
				else {
					int hh = star[k] - P[i];
					if(hh * 2 <= dis || hh + xx <= dis) continue;
					else break;
				}
			}
			it = k;
			if(it == (int)star.size()) return 1;
		}
		else {
			int k;
			int dis = x;
			for(k = it;k <= (int)star.size() - 1;k ++) {
				if(star[k] < P[i]) continue;
				else {
					int hh = star[k] - P[i];
					if(hh <= dis) continue;
					else break;
				}
			}
			it = k;
			if(it == (int)star.size()) return 1;			
		}
	}
	if(it == (int)star.size()) return 1;
	return 0;
}

int main(void) {
	scanf("%d",&n);
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i ++) if(s[i] == 'P') P.push_back(i); else if(s[i] == '*') star.push_back(i);
	int l = 0 , r = n * 10;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			ans = mid; r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
}