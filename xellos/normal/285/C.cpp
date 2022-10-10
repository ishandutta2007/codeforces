// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
#define M 1000000007
// mylittlepony
using namespace std;

long long Abs(int x) {if(x < 0) return (long long)(-x); else return (long long)x;}

int main() {
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	sort(V.begin(),V.end());
	
	long long ans =0;
	for(int i =0; i < N; i++)
		ans +=Abs(V[i]-i-1);
	cout << ans << endl;
	return 0;}

// look at my code
// my code is amazing