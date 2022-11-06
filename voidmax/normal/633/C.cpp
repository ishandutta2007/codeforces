#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <time.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

void Contur(char &a) {
    if (a <= 'Z')
        a += 'a' - 'A';
}

string f(string a) {
    reverse(a.begin(), a.end());
    For(i, 0, a.size()) Contur(a[i]);
    return a;
}


typedef long long base;
const base p = 1e9 + 9, q = 107;
base Pow[10001];
int Way[10001];
string a;
int n, m;
string arr[100001];
map <int, int> MyHash[1001];

int hashing(string a) {
    base cnt = 0;
    For(i, 0, a.size())
        cnt = (cnt + a[i] * Pow[i]) % p;
    return cnt;
}

void res(int Id) {
    if (Way[Id] == -1) return;
    res(Id - arr[Way[Id]].size());
    cout << arr[Way[Id]] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	//read(FileName);
    cin >> n;
    cin >> a;
    Pow[0] = 1;
    For(i, 1, n) {
        Pow[i] = Pow[i - 1] * q % p;
    }
    cin >> m;
    For(i, 1, m + 1) {
        cin >> arr[i];
        MyHash[arr[i].size()][hashing(f(arr[i]))] = i;
    }
    Way[0] = -1;
    For(i, 0, n) {
        if (!Way[i]) continue;
        base cnt = 0;
        For(S, 1, min(1001, (int)n - i + 1)) {
            cnt = (cnt + a[i + S - 1] * Pow[S - 1]) % p;
            if (MyHash[S].count(cnt)) {
                Way[i + S] = MyHash[S][cnt];
            }
        }
    }
    res(n);
}