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
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		if(i > 0)b[i] = b[i - 1];
		if(a[i] == mx)b[i] += 1;
	}
	const int BLOCK = 320;
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
	vector<bool> was(n, false);
	auto SolveSmall = [&](int x){
		int res = 0, sz = (int)pos[x].size();
		vector<int> vec;
		vec.clear();
		function<void(int)> add = [&](int i){
			if(!was[i]){
				was[i] = true;
				vec.push_back(i);
			}
		};
		add(0); //vec.push_back(0);
		add(n - 1); //vec.push_back(n - 1);
		function<void(int)> adj = [&](int wh){
			for(int i : {wh - 1, wh + 1}){
				if(i >= 0 && i < n && a[i] != x && a[i] != mx){
					add(i); //vec.push_back(i);
				}
			}
		};
		for(int occ = 0; occ < sz; occ++){
			int i = pos[x][occ];
			add(i); //vec.push_back(i);
			int cc = lower_bound(pos[mx].begin(), pos[mx].end(), i) - pos[mx].begin();
			for(int j = max(0, cc - sz - 1); j <= min((int) pos[mx].size() - 1, cc + sz + 1); j++){
				//if(j >= 0 && j < (int)pos[mx].size()){
					add(pos[mx][j]); //vec.push_back();
					adj(pos[mx][j]);
				//}
			}
			/*int cnt = sz + 1;
			while(cnt > 0 && it != pos[mx].end()){
				add(*tivec.push_back(*it);
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
			}*/
		}
		sort(vec.begin(), vec.end());
		vector<int> rem;
		int pref = 0;
		lst[n] = -1;
		for(int i = 0; i < vec.size(); i++){
			if(a[vec[i]] == x)pref += 1;
			int bal = pref - b[vec[i]];
			if(lst[bal + n] != -2){
				res = max(res, vec[i] - lst[bal + n]);
			}else{
				lst[bal + n] = vec[i];
				rem.push_back(bal + n);
			}
			was[vec[i]] = false;
		}
		for(int i : rem)lst[i] = -2;
		return res;
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == mx || pos[i].empty())continue;
		if(pos[i].size() >= BLOCK){
			ans = max(ans, SolveBig(i));
		}else{
			ans = max(ans, SolveSmall(i));
		}
	}
	cout << ans << '\n';
	return 0;
}