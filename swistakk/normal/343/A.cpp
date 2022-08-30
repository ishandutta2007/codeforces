#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define ll long long int
#define MP make_pair
#define PB push_back

using namespace std;

long long cnt = 0;

ll gcd(ll a, ll b) {
	if (a == b) {
		cnt++;
		return 0;
	}
	if (a == 0 || b == 0) {
		return 0;
	}
	
	if (b > a) {
		cnt += b / a;
		return gcd(a, b % a);
	} else {
		cnt += a / b;
		return gcd(a % b, b);
	}
}

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	
	ll a, b;
	cin>>a>>b;
	gcd(a, b);
	cout<<cnt<<endl;
	// nie zapomnij o ll
	return 0;
}