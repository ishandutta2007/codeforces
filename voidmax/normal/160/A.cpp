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
#define inf 1e9 + 1
#define eps 1e-6
#define ll long long

using namespace std;

int n, Sum;
vector <int> Array;

void Clear(vector <int> &a) {
    vector <int> b; swap(a, b);
}

void Sort(vector <int> &a) {
    if (a.size() < 2) return;
    vector <int> b[2];
    For(i, 0, a.size()) b[i & 1].push_back(a[i]);
    Sort(b[0]); Sort(b[1]); Clear(a);
    b[0].push_back(-1); b[1].push_back(-1);
    int L[2]; L[0] = L[1] = 0;
    For(i, 0, (int)b[0].size() + b[1].size() - 2) {
        a.push_back(max(b[0][L[0]], b[1][L[1]]));
        ++L[b[0][L[0]] < b[1][L[1]]];
    }
}

int main() {
    //ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a; Sum += a;
        Array.push_back(a);
    }
    Sort(Array);
    int cnt = 0;
    For(i, 0, n) {
        cnt += Array[i];
        Sum -= Array[i];
        if (cnt > Sum) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}

//10
//1 2 3 4 5 1 2 3 4 5