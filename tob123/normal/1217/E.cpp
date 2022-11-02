#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<ll,ll> pii;

const int n = 2e5+10;
const ll INF = 1e15;

int N, M;
int A[n];

const int offset=256*1024-1;
//const int offset=7;
const int size = 2*offset+1;
vector<pii> S[size];

void printP(pii x){
	cout << "(" << x.first << "," << x.second << ") ";
}

int par(int x){
	return (x-1)/2;
}
int left(int x){
	return 2*x+1;
}
int right(int x){
	return 2*x+2;
}

pii comb(pii a, pii b){
	if(a.first > b.first)
		swap(a, b);
	if(a.second < b.first)
		return make_pair(a.first, a.second);
	else
		return make_pair(a.first, b.first);
}

vector<pii> comb2(vector<pii>& a, vector<pii>& b){
	vector<pii> res(9);
	for(int i=0; i<9; i++){
		res[i] = comb(a[i], b[i]);
	}
	return move(res);
}

void update(int ind, int val){
	ind += offset;
	int tmp = val;
	for(int i=0; i<9; i++){
		if(tmp%10){
			S[ind][i].first = val;
		}
		else
			S[ind][i].first = INF;
		tmp /= 10;
	}
	while(ind != 0){
		ind = par(ind);
		S[ind] = comb2(S[left(ind)], S[right(ind)]);
	}
}

vector<pii> res;
void query(int l, int r, int curl=0, int curr=offset, int cur=0){
	if(l <= curl && r >= curr){
		res = comb2(res, S[cur]);
		return;
	}
	if(l > curr || r < curl){
		return;
	}
	int m = (curl+curr)/2;
	query(l, r, curl, m, left(cur));
	query(l, r, m+1, curr, right(cur));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0; i<size; i++)
		S[i] = vector<pii>(9, {INF,INF});

	cin >> N >> M;
	for(int i=0; i<N; i++){
		int x;
		cin >> x;
		update(i, x);
	}

	int t, a, b;
	for(int i=0; i<M; i++){
		cin >> t >> a >> b;
		if(t == 1){
			update(a-1, b);
		}
		else{
			ll best = INF;
			res = vector<pii>(10, {INF, INF});
			query(a-1, b-1);
			//printS();
			/*
			for(int i=0; i<sz(res); i++){
				printP(res[i]);
			}
			cout << endl;
			*/
			for(int i=0; i<9; i++){
				best = min(best, (ll) res[i].first + res[i].second);
			}
			if(best < INF){
				cout << best << "\n";
			}
			else{
				cout << -1 << "\n";
			}
		}
	}

  return 0;
}