#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int B, G, N;
	cin >> B >> G >> N;
	int minG = max(0, N-B), maxG = min(N, G);
	int minB = max(0, N-G), maxB = min(N, B);
	cout << min(maxG-minG+1, maxB-minB+1) << endl;

  return 0;
}