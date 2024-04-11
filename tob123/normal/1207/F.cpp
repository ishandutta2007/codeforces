#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 5e5+1;
const int srt = 500;

int Q;
vector<int> res;
int B[n];
int sum[srt][srt];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> Q;
	for(int q=0; q<Q; q++){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1){
			for(int i=1; i<srt; i++){
				sum[i][x%i] -= B[x];
			}
			B[x] += y;
			for(int i=1; i<srt; i++){
				sum[i][x%i] += B[x];
			}
		}
		else{
			if(x < srt){
				res.push_back(sum[x][y]);
			}
			else{
				int cur = 0;
				for(int i=y; i<n; i+=x){
					cur += B[i];
				}
				res.push_back(cur);
			}
		}
	}
	for(int x : res){
		cout << x << "\n";
	}

  return 0;
}