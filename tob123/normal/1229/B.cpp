#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
//typedef pair<ll,ll> pii;

const int n = 1e5+10;
const ll MOD = 1e9+7;

int N;
ll X[n];
vector<int> G[n];
int jmp[20][n];
ll val[20][n];
int L[n];
pair<ll,int> v[n];

ll gcd(ll a, ll b){
	ll tmp ;
	while ( b ) { a %= b ; tmp = a ; a = b ; b = tmp ;}
	return a ;
}

void dfs(int cur, int last){
	if(X[cur] != 0)
		v[cur] = {X[cur], L[cur]};
	for(int x : G[cur]){
		if(x == last)
			continue;
		v[x] = v[cur];
		jmp[0][x] = cur;
		val[0][x] = gcd(X[cur], X[x]);
		L[x] = L[cur]+1;
		dfs(x, cur);
	}
}

pair<int,ll> query(int a, ll g){
	ll res = X[a];
	for(int i=19; i>=0; i--){
		ll newR = gcd(val[i][a], res);
		if(newR >= g || newR == 0){
			a = jmp[i][a];
			res = newR;
		}
	}
	if(L[a] >= 0){
		res = gcd(res, val[0][a]);
	}
	return make_pair(L[a]-1, res);
}

int main(){
	cin >> N;
	v[0] = {-1, -1};
	for(int i=0; i<N; i++){
		cin >> X[i];
	}
	for(int i=0; i<N-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	jmp[0][0] = 0;
	val[0][0] = X[0];
	dfs(0, -1);
	for(int i=1; i<20; i++){
		for(int j=0; j<N; j++){
			jmp[i][j] = jmp[i-1][jmp[i-1][j]];
			val[i][j] = gcd(val[i-1][j], val[i-1][jmp[i-1][j]]);
		}
	}
	/*
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			cout << val[i][j] << " ";
		}
		cout << endl;
	}
	*/
	ll erg = 0;
	for(int i=0; i<N; i++){
		if(v[i].first == -1)
			continue;
		ll cur = v[i].first;
		int l = v[i].second;
		while(l >= 0){
			auto p = query(i, cur);
			//cout << "query " << i << " " << cur << ": " << p.first << " " << p.second << endl;
			erg += (l-p.first)*cur;
			cur = p.second;
			l = p.first;
			erg %= MOD;
		}
	}
	cout << erg << endl;

  return 0;
}