#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void test_case(){
	int n, t, x, cnt = 0, last = 0;
	cin >> n;
	vi v(n);
	priority_queue<ii> q;
	while(n--){
		cin >> t;
		if(t == 1){
			cin >> x;
			q.push({x, -cnt});
			cnt++;
		}
		if(t == 2){
			while(v[last] == 1)last++;
			v[last] = 1;
			cout << last+1 << " ";
		}
		if(t == 3){
			while(v[-q.top().s] == 1)q.pop();
			v[-q.top().s] = 1;
			cout << -q.top().s + 1 << " ";
			q.pop();
		}
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}