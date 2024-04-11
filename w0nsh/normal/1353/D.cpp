#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int A[200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin>> t;
	while(t--){
		int n;
		std::cin >> n;
		int value = 1;
		std::priority_queue<PR<PII, PII> > que;

		auto add = [&](int a, int b){
		//	std::cout << "add " << a << " " << b << std::endl;
			que.push(MP(MP(b-a+1, -a), MP(a, b)));
		};

		add(0, n-1);

		while(SZ(que)){
			auto cur = que.top().Y;
			que.pop();
			int a = cur.X;
			int b = cur.Y;
			int mid = (a+b)/2;
			A[mid] = value++;
			
			if(a <= mid-1){
				add(a, mid-1);
			}
			if(mid+1 <= b){
				add(mid+1, b);
			}
		}

		FOR(i, n) std::cout << A[i] << " ";
		std::cout << "\n";
	}

	return 0;
}