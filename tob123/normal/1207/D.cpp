#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 998244353;

int N;
vector<pii> A;

ll calcP(){
	sort(A.begin(), A.end());
	ll pos1 = 1;
	ll bs = 1, lst = -1;
	for(int i=0; i<N; i++){
		if(A[i].first == lst){
			bs++;
		}
		else{
			lst = A[i].first;
			/*
			pos1 *= bs * (bs+1) / 2 % MOD;
			pos1 %= MOD;
			*/
			bs = 1;
		}
		//cout << bs << " ";
		pos1 *= bs;
		pos1 %= MOD;
	}
	/*
	pos1 *= bs * (bs+1) / 2 % MOD;
	pos1 %= MOD;
	*/
	//cout << bs << endl;
	return pos1;
}

int main(){
	cin >> N;
	A.resize(N);
	for(int i=0; i<N; i++){
		cin >> A[i].first >> A[i].second;
	}
	ll pos1 = calcP();
	for(int i=0; i<N; i++){
		swap(A[i].first, A[i].second);
	}
	ll pos2 = calcP();
	bool f = true;
	for(int i=0; i<N-1; i++){
		if(A[i].second > A[i+1].second)
			f = false;
	}
	ll pos3 = 0;
	if(f){
		for(int i=0; i<N; i++){
			A[i].first *= N+1;
			A[i].first += A[i].second;
		}
		pos3 = calcP();
	}
	ll res = 1;
	for(ll i=1; i<=N; i++){
		res *= i;
		res %= MOD;
	}
	//cout << pos1 << " " << pos2 << " " << pos3 << endl;
	res += pos3;
	res += 2*MOD;
	res -= pos1 + pos2;
	res %= MOD;
	cout << res << endl;

  return 0;
}