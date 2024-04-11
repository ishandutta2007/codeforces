#include <iostream>
#include <algorithm>
#include <set>
#include <time.h>
#include <map>
#include <random>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define mp make_pair
#define x first
#define y second
#define elif else if
#define point pair <double, double>
#define inf 1e18
#define eps 1e-6
#define ll long long

using namespace std;

int n;
multiset <int> arr;
vector <int> ans;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    cin >> n;
    For (i, 0, n) {
        For(j, 0, n) {
            int a;
            cin >> a;
            arr.insert(-a);
        }
    }
    For(i, 0, n) {
        int New = *arr.begin();
        For(j, 0, i) {
            arr.erase(arr.find(-gcd(-New, ans[j])));
            arr.erase(arr.find(-gcd(-New, ans[j])));
        }
        arr.erase(arr.begin());
        ans.push_back(-New);
        cout << -New << ' ';
    }
}