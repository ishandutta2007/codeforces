#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e5 + 5;

int N;
ll T[n], A[n], B[n];
vector<tuple<ll, bool, ll>> E;

int main(){
	cin >> N;
	for(int i = 0; i < N; ++i)	{
		cin >> A[i] >> B[i] >> T[i];
		E.push_back({A[i], false, i});
		E.push_back({B[i], true, i});
	}
	sort(E.begin(), E.end());
	ll nextX = 0;
	ll c = 0;
	bool p = false;
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
	for(int zz = 0; zz < E.size(); ++zz){
		int i; ll x; bool end;
		tie(x, end, i) = E[zz];
		//cerr << "x: "<< x << endl;
		if(x >= nextX){
			c += p;
			//cerr << "skipping to " << nextX  << " added: " << p << endl;
			p = false;
			// apply upto <=x
			while(!Q.empty()){
				int j = Q.top().second;
				if(nextX + T[j] > B[j]){
					Q.pop();
					continue;
				}
				ll cc = (min(B[j], x) - nextX) / T[j];
				//cerr << "taking " << j << " from " << nextX << " to " << nextX + cc*T[j] << " ( " << cc << "x)"<<endl;
				c += cc;
				nextX = nextX + cc*T[j];
				//cerr << "nextX is now: "<< nextX << endl;
				if(cc == 0)
				break;
			}
			// propose
			while(!Q.empty()){
				int j = Q.top().second;
				if(nextX + T[j] > B[j]){
					Q.pop();
					continue;
				}
				p = true;
				nextX = nextX + T[Q.top().second];
				break;
			}
			// nextX is now <= x
		}
		
		if(end){

		}else{
			//start
			Q.push({T[i], i});
			if(p)
				nextX = min(nextX, x + T[i]);
			else
				nextX = x + T[i];
			p = true;
		}
	}
	cout << c << endl;
	return 0;
}