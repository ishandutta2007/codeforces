#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	array<vector<int>, 2> p{};
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		p[a[i] & 1].push_back(i);
	}
	if((int)p[0].size() >= 3 || (int)p[0].size() >= 1 && (int)p[1].size() >= 2){
		int i, j, k;
		if((int)p[0].size() >= 3){
			i = p[0][0], j = p[0][1], k = p[0][2];
		}
		else{
			i = p[0][0], j = p[1][0], k = p[1][1];
		}
		int sum = a[i] + a[j] + a[k] >> 1;
		cout << "YES\n";
		cout << sum - a[i] << " " << sum - a[j] << " " << sum - a[k] << " ";
		int last = sum - a[i];
		for(auto l = 0; l < n; ++ l){
			if(l != i && l != j && l != k){
				cout << (last = a[l] - last) << " ";
			}
		}
		cout << "\n";
		return 0;
	}
	map<int, vector<int>> s;
	vector<int> c(n);
	fill(c.begin(), c.begin() + n / 2, 1);
	mt19937 rng(1564);
	for(auto start = chrono::high_resolution_clock::now(); chrono::duration<double>(chrono::high_resolution_clock::now() - start).count() <= 0.7; ){
		shuffle(c.begin(), c.end(), rng);
		int sum = 0;
		for(auto i = 0; i < n; ++ i){
			if(c[i]){
				sum += a[i];
			}
		}
		if(s.count(sum) && c != s[sum]){
			auto d = s[sum];
			vector<int> left, right, used(n);
			for(auto i = 0; i < n; ++ i){
				if(c[i] ^ d[i]){
					(c[i] ? left : right).push_back(a[i]);
					used[i] = true;
				}
			}
			vector<int> cycle((int)left.size() + (int)right.size());
			for(auto i = 1; i < (int)cycle.size(); ++ i){
				if(i & 1){
					cycle[i] = left[i >> 1] - cycle[i - 1];
				}
				else{
					cycle[i] = right[i - 1 >> 1] - cycle[i - 1];
				}
			}
			cout << "YES\n";
			for(auto x: cycle){
				cout << x << " ";
			}
			int last = cycle.back();
			for(auto i = 0; i < n; ++ i){
				if(!used[i]){
					cout << (last = a[i] - last) << " ";
				}
			}
			cout << "\n";
			return 0;
		}
		s[sum] = c;
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////