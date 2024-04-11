#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

const int MAXN = 500005;

pair<int, pair<int, int> > pp[MAXN];

int fenw[MAXN], n, mx[MAXN];

int get_max(int ind){
	int ans = 0;
	for(int i = ind; i >= 0; i = (i & (i + 1)) - 1){
		ans = max(ans, fenw[i]);
	}
	return ans;
}

void update(int ind, int v){
	if (mx[ind] >= v){
		return;
	}
	mx[ind] = v;
	for(int i = ind; i < n; i |= (i + 1)){
		fenw[i] = max(fenw[i], v);
	}
}

map<int, int> ind;

int bb[MAXN], ii[MAXN], ppp[MAXN];

int main(){	
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	int i, j, a;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &bb[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &ii[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &ppp[i]);
	}
	for(i = 0; i < n; i++){
		pp[i] = mp(bb[i], mp(ii[i], ppp[i]));
	}
	sort(pp, pp + n);
	for(i = 0; i < n; i++){
		ind[pp[i].second.first] = 0;
	}
	map<int, int>::iterator it;
	for(i = 0, it = ind.begin(); it != ind.end(); i++, it++){
		it->second = n - 1 - i;
	}
	for(i = 0; i < n; i++){
		pp[i].second.first = ind[pp[i].second.first];
	}
	int ans = 0;
	for(j = i = n - 1; i >= 0; i--){
		if (i != n - 1 && pp[i].first != pp[j].first){
			for(; j > i; j--){
				update(pp[j].second.first, pp[j].second.second);
			}
		}
		a = get_max(pp[i].second.first - 1);
		if (a > pp[i].second.second){
			ans++;
		}		
	}
	printf("%d", ans);
}