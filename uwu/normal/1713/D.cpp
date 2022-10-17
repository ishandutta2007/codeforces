#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
	while (T--){
		int N; cin >> N;
		vector<int> a;
		for (int i = 1; i <= (1 << N); ++i){
			a.push_back(i);
		}

		auto qry = [&](int x, int y){
			cout << "? " << x << " " << y << '\n';
			cout.flush();
			int ret; cin >> ret;
			return ret;
		};

		auto get_big = [&](int x, int y){
			int ret = qry(x, y);
			if (ret == 1) return x;
			else return y;
		};

		while (a.size() != 1){
			vector<int> nxt;
			if (a.size() == 2){
				nxt.push_back(get_big(a[0], a[1]));
			}
			else{
				while (!a.empty()){
					int a1 = a.back(); a.pop_back();
					int a2 = a.back(); a.pop_back();
					int a3 = a.back(); a.pop_back();
					int a4 = a.back(); a.pop_back();
					int tmp = qry(a2, a3);
					if (tmp == 0){
						nxt.push_back(get_big(a1, a4));
					}
					if (tmp == 1){
						nxt.push_back(get_big(a2, a4));
					}
					if (tmp == 2){
						nxt.push_back(get_big(a1, a3));
					}
				}
			}
			swap(a, nxt);
		}
		cout << "! " << a[0] << '\n';
		cout.flush();
	}
}