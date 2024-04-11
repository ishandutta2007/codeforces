#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> pos(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		--a[i];
		pos[a[i]].push_back(i);
	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		if(pos[i].size() > pos[mx].size()){
			mx = i;
		}
	}
	const int BLOCK = 1;
	vector<int> lst(2 * n + 1, -2);
	auto SolveBig = [&](int x){
		int pref = 0;
		vector<int> rem;
		lst[n] = -1;
		int res = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == x)pref += 1;
			if(a[i] == mx)pref -= 1;
			if(lst[pref + n] != -2){
				res = max(res, i - lst[pref + n]);
			}else{
				rem.push_back(pref + n);
				lst[pref + n] = i;
			}
		}
		for(int i : rem)lst[i] = -2;
 		return res;
	};
	auto SolveSmall = [&](int x){
		int res = 0, sz = (int)pos[x].size();
		vector<int> vec;
		function<void(int)> adj = [&](int wh){
			for(int i = wh - 1; i <= wh + 1; i++){
				if(i >= 0 && i < n && a[i] != x && a[i] != mx){
					vec.push_back(i);
				}
			}
		};
		for(int occ = 0; occ < sz; occ++){
			int i = pos[x][occ];
			vec.push_back(i);
			auto it = lower_bound(pos[mx].begin(), pos[mx].end(), i);
			int cnt = sz + 1;
			while(cnt > 0 && it != pos[mx].end()){
				vec.push_back(*it);
				adj(*it);
				it++;
				cnt--;
			}
			it = lower_bound(pos[mx].begin(), pos[mx].end(), i);
			cnt = sz + 1;
			while(cnt > 0 && it != pos[mx].begin()) {
				--it;
				vec.push_back(*it);
				adj(*it);
				cnt--;
			}
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		vector<int> rem;
		lst[n] = -1;
		int pref = 0;
		for(int i : vec){
			if(a[i] == x)pref += 1;
			if(a[i] == mx)pref -= 1;
			if(lst[pref + n] != -2){
				res = max(res, i - lst[pref + n]);
			}else{
				lst[pref + n] = i;
				rem.push_back(pref + n);
			}
		}
		for(int i : rem)lst[i] = -2;
		return res;
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == mx)continue;
		if(pos[i].size() >= BLOCK){
			ans = max(ans, SolveBig(i));
		}else{
			ans = max(ans, SolveSmall(i));
		}
	}
	cout << ans << '\n';
	return 0;
}