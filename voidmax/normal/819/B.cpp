// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//#include "grader.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define read(FILENAME) assert(freopen((FILENAME + ".in").c_str(), "r", stdin))
#define write(FILENAME) assert(freopen((FILENAME + ".out").c_str(), "w", stdout))
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
template <typename A, typename B> void chkmin(A &x, B y) {if (x > y) x = y;}
template <typename A, typename B> void chkmax(A &x, B y) {if (x < y) x = y;}
      
typedef pair <int, int> point;
      
const string FILENAME = "input";
const int MAXN = 1e6 + 1, p = 1e9 + 7, q = 288321;

int n; 
int cntL, cntR;
long long sumL, sumR;
int arr[MAXN];
int ans_id;
long long ans = 1e18;

set <int> event[MAXN];

int main() {
    srand(time(0));
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n;
   	for (int i = 0; i < n; ++i) {
   		cin >> arr[i];
   		--arr[i];
   		if (arr[i] < i) {
   			sumR += i - arr[i];
   			++cntR;
   			//cout << (n - i) + arr[i] << ':' << i << endl;
   			event[(n - i) + arr[i]].insert(i);
   		} else {
   			sumL += arr[i] - i;
   			++cntL;
   			//cout << arr[i] - i << ':' << i << endl;
   			event[arr[i] - i].insert(i);
   		}
   	}
   	for (int k = 0; k < n; ++k) {
   		//cout << sumL << ' ' << sumR << ' ' << cntL << ' ' << cntR << endl;
   		if (ans > sumL + sumR) {
   			ans = sumL + sumR;
   			ans_id = k;
   		}
   		int j = ((n - 1) - k) % n, r = event[k].size();
		//cout << event[k].size() << endl;
		cntL -= r;
   		cntR += r;
   		sumL -= cntL;
   		sumR += cntR;
   		++cntL;
   		--cntR;
   		//cout << arr[j] << endl;
   		//cout << sumL << ' ' << sumR << ' ' << cntL << ' ' << cntR << endl;
   		sumR -= n - arr[j];
   		sumL += arr[j] - 0;
   	}
   	cout << ans << ' ' << ans_id << endl;
}