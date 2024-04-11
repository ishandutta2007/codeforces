/*
 - - - - - - - -
 
  *********
 ***********
 ***     ***
 ***     ***
 ***     ***
 ***********
 ***********
 ***     ***
 ***     ***
 ***     ***
 
 - - - - - - - -
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

int n, p, q;
string a;
int arr[1000000];
long long cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {int a; cin >> a; arr[a] = i;}
    For(i, 1, n) cnt += abs(arr[i] - arr[i + 1]);
    cout << cnt << endl;
}