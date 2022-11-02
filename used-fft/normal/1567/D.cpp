#include <bits/stdc++.h>
using namespace std;
#define int long long

#define p(Z) ((int)pow(10, Z))

multiset<int> res;
int left_;

void add(int v){
	int i = *res.begin();
	if(!i) --left_;
	res.erase(res.begin());
	res.insert(i + v);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int s, n; cin >> s >> n;

		res.clear();
		for(int i=0; i<n; ++i) res.insert(0);

		left_ = n;

		for(int d=10; --d>=0; ){
			int lim = n * 9;
			int m = p(d);

			for(int i=lim; i; --i){
				if(m * i <= s && left_ <= i + (s - m * i)){
					s -= m * i;
					int todo = i;

					for(int j=0; j<n; ++j){
						if(todo) add(m), --todo;
					}
					while(todo) add(m*min(todo, 8LL)), todo -= min(todo, 8LL);

					break;
				}
			}
		}
		for(int i : res) cout << i << ' ';
		cout << '\n';
	}
}