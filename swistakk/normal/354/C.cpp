#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back

using namespace std;

const int N = 1001 * 1001;

int sumpref[N];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int n, k;
	cin>>n>>k;
	int res = k + 1;
	int max_val = 1;
	int min_val = N;
	for (int i = 1; i <= n; i++) {
		int a;
		cin>>a; 
		max_val = max(max_val, a);
		min_val = min(min_val, a);
		sumpref[max(0, a - k)]++;
		sumpref[a + 1]--;
	}
	res = min(k + 1, min_val);
	for (int i = 1; i <= max_val; i++) {
		sumpref[i] = sumpref[i] + sumpref[i - 1];
	}
	for (int i = k + 2; i <= max_val; i++) {
		int acc = 0;
		for (int j = 1; i * j <= max_val; j++) {
			acc += sumpref[i * j];
		}
		if (acc == n) {
			res = i;
		}
	}
	cout<<res<<endl;
		
	
	// nie zapomnij o ll
	return 0;
}