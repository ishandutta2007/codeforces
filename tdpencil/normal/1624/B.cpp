#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <stack>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <cmath>
#include <string>
using namespace std;
int a, b, c, t;
int nsqrt(int x) {
	int lb=0,rb=2*sqrt(x)+5;

	while(lb<rb) {
		int mid=(lb+rb)/2;
		if(mid*mid>=x) rb=mid;
		else lb=mid+1;
	}
	return lb*lb==x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	while(t--) {
		cin >> a >> b >> c;
		if(true) {
			int r=b-a;
			if((b+r)%c==0&&(b+r)>=1) {
				cout << "YES\n";
				continue;
			}
		}

		if(true) {
			int r=c-a;
			if(r%2==0) {
				r/=2;
				if((a+r)%b==0&&c-(a+r)==(a+r)-a) {
					cout << "YES\n";
					continue;
				}
			}
			
		}

		if(true) {
			int r=c-b;
			int x=b-r;
			if(x%a==0&&x>=1) {
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
}