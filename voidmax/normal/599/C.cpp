//#include "grader.h"
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define x first
#define y second
#define point pair <int, int>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
using namespace std;

int m, n;
int cnt = 0;
int arr[100001];
vector <pair <int, int>> nums;
bool used[100001];
long long num, c;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 1, n + 1) {
        int a; cin >> arr[i];
        nums.push_back({arr[i], i});
    }
    sort(nums.begin(), nums.end());
    For(i, 0, n) arr[nums[i].y] = i + 1;
    For(i, 1, n + 1) {
        int a; a = arr[i]; a -= num;
        c += a;
        if ((-num + i) * (i - num + 1) / 2 == c) {
            c = 0; ++cnt; num = i;
        }
    }
    cout << cnt << endl;
}