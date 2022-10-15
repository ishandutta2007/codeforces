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
	int n, q;
	string str;
	cin >> n;
	map<string, int> cnt;
	map<string, string> superStr;
	while(n--){
		cin >> str;
		set<string> s;
		for(int i = 0; i < str.size(); i++){
			for(int j = 1; i+j <= str.size(); j++)
				s.insert(str.substr(i, j));
		}
		for(auto x: s){
			cnt[x]++;
			superStr[x] = str;
		}
	}
	cin >> q;
	while(q--){
		cin >> str;
		cout << cnt[str] << " ";
		if(cnt[str]){
			cout << superStr[str] << endl;
		}
		else
			cout << "-" << endl;
	}
	
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