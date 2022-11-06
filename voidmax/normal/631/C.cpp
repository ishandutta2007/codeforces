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

int n, m;
vector <int> a;
vector <int> Size;
vector <int> Type;
vector <int> Stack;
int NextMore[200001];
vector <int> func;
void cond(int i) {
    if (i == -1) return;
    cond(NextMore[i]);
    func.pb(i);
}

void res(int L, int R, vector <int> &a, int i) {
    if (i == func.size()) {
        //cout << '(';
        if (L < R) For(j, L, R) cout << a[j] << ' ';
        else       Out(j, L, R) cout << a[j] << ' ';
        return;
        //cout << ')';
    }
    int Ln = min(L, R), Rn = max(L, R);
    int S = Rn - Ln;
    S -= Size[func[i]];
    if (L < R) {
        R -= S;
    } else {
        R += S;
    }
    Ln = min(L, R), Rn = max(L, R);
    if (Type[func[i]] == 1) {
        res(Ln, Rn, a, i + 1);
    } else {
        res(Rn, Ln, a, i + 1);
    }
    if (L < R) {
        For(j, R, R + S) cout << a[j] << ' ';
    } else {
        Out(j, R, R - S) cout << a[j] << ' ';
    }
}

int main() {
    //read(FileName);
	ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 0, n) {
        int b; cin >> b;
        a.pb(b);
    }
    For(i, 0, m) {
        int a, b; cin >> a >> b;
        Size.pb(b); Type.pb(a);
        NextMore[i] = -1;
    }
    Out(i, m, 0) {
        int Last = Stack.size(); --Last;
        while (Last != -1 && Size[Stack[Last]] < Size[i]) {
            NextMore[Stack[Last]] = i;
            Stack.pop_back(); --Last;
        }
        Stack.pb(i);
    }
    cond(m - 1);
    vector <int> Copy;
    For(i, 0, Size[func[0]]) Copy.pb(a[i]);
    sort(Copy.begin(), Copy.end());
    res(0, Size[func[0]], Copy, 0);
    For(i, Size[func[0]], n) cout << a[i] << ' ';
}