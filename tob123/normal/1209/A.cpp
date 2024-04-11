#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<int> A;

int main(){
	cin >> N;
	A.resize(N);
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<int> cur;
	for(int i=0; i<N; i++){
		bool pos = false;
		for(int x : cur){
			pos |= A[i]%x == 0;
		}
		if(!pos)
			cur.push_back(A[i]);
	}
	cout << sz(cur) << endl;

  return 0;
}