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

typedef long long base;
int n;
string a;
int cnt[3];
bool arr[201][201][201];


int main() {
    srand(time(0));
	ios::sync_with_stdio(false);
	//write(FileName);
    //cin >> p >> q;
    cin >> n >> a;
    For(i, 0, n) {
        if (a[i] == 'B') ++cnt[0];
        if (a[i] == 'G') ++cnt[1];
        if (a[i] == 'R') ++cnt[2];
    }
    arr[cnt[0]][cnt[1]][cnt[2]] = true;
    Out(S, n + 1, 2) {
        For(a, 0, S + 1) {
            For(b, 0, S - a + 1) {
                int c[3];
                c[0] = a;
                c[1] = b;
                c[2] = S - a - b;
                if (!arr[c[0]][c[1]][c[2]]) continue;
                For(k, 0, 3) {
                    if (c[k] >= 2) {
                        c[k] -= 1;
                        arr[c[0]][c[1]][c[2]] = true;
                        c[k] += 1;
                    }
                    if (c[k] && c[(k + 1) % 3]) {
                        --c[k]; --c[(k + 1) % 3];
                        ++c[(k + 2) % 3];
                        arr[c[0]][c[1]][c[2]] = true;
                        ++c[k]; ++c[(k + 1) % 3];
                        --c[(k + 2) % 3];
                    }
                }
            }
        }
    }
    if (arr[1][0][0]) cout << 'B';
    if (arr[0][1][0]) cout << 'G';
    if (arr[0][0][1]) cout << 'R';
}