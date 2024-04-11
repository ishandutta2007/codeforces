#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void test_case(){
	int n;
	cin >> n;
	vector<int> v(2*n);
	for(auto &x: v)cin >> x;
	int ans = INF;
	if(is_sorted(v.begin(), v.end())) ans = 0;
	{
		vector<int> v1 = v;
		for(int i = 0; i < 2*n; i++){
			if(i%2){
				for(int j = 0; j < 2*n; j+=2){
					swap(v1[j], v1[j+1]);
				}
			}
			else{
				for(int j = 0; j < n; j++){
					swap(v1[j], v1[j+n]);
				}
			}
			if(is_sorted(v1.begin(), v1.end()))ans = min(ans, i+1);
		}
	}
	{
		vector<int> v1 = v;
		for(int i = 0; i < 2*n; i++){
			if(i%2==0){
				for(int j = 0; j < 2*n; j+=2){
					swap(v1[j], v1[j+1]);
				}
			}
			else{
				for(int j = 0; j < n; j++){
					swap(v1[j], v1[j+n]);
				}
			}
			if(is_sorted(v1.begin(), v1.end()))ans = min(ans, i+1);
		}
	}
	if(ans==INF)ans = -1;
	cout << ans << endl;
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