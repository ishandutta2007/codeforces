#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<pii> D;
vector<int> X;
vector<pii> G;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	D.resize(N);
	for(int i=0; i<N; i++){
		cin >> D[i].first;
		D[i].second = i;
	}
	sort(D.rbegin(), D.rend());
	X.resize(N);
	for(int i=0; i<N; i++){
		X[i] = 2*D[i].second+2;
		if(i != 0){
			G.push_back(make_pair(X[i], X[i-1]));
		}
	}
	for(int i=0; i<N; i++){
		int con = i+D[i].first-1;
		G.push_back(make_pair(2*D[i].second+1, X[con]));
		if(con == sz(X)-1)
			X.push_back(2*D[i].second+1);
	}
	for(auto p : G){
		cout << p.first << " " << p.second << "\n";
	}

  return 0;
}