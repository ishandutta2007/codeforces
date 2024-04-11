#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

vector<int> head, len, c;
vector<vector<int>> ans;
ll n;

ll find(ll n) {
    return head[n] == n? n: head[n] = find(head[n]);
}

void change(vector<int> &ret) {
    stack<vector<int>> stack;
    ll idx = 0;
    for (auto seg : ret) {
        vector<int> vec;
        REP(i, seg) vec.eb(c[idx++]);
        stack.emplace(vec);
    }

    idx = 0;
    while (!stack.empty()) {
        vector<int> vec = stack.top(); stack.pop();
        for (auto num : vec) {
            c[idx++] = num;
        }
    }
}

void genAns(ll idxEnd, ll idxFront) {
    ll idx = 0;
    vector<int> ret;
    while (idx < n) {
        if (idx == idxEnd) {
            ret.eb(idxFront-idxEnd);
            idx += idxFront-idxEnd;
        }
        else {
            ret.eb(len[c[idx]]);
            idx += len[c[idx]];
        }
    }
    
    len[c[idxFront]] += len[c[idxEnd]];
    head[find(c[idxEnd])] = find(c[idxFront]);

    change(ret);
    ans.eb(ret);
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        c = vector<int>(n);
        REP(i, n) {cin >> c[i];}

        head = vector<int>(n+1), len = vector<int>(n+1);
        FOR(i, 1, n) {head[i] = i; len[i] = 1;}

        REP(i, n) {
            REP(j, n) {
                ll front = c[j];
                ll idxFront = j;
                if (find(c[j]) == c[j]) {
                    ll next = front + len[front];
                    ll idxEnd  = -1;
                    REP(k, j) if (c[k] == next) {
                        idxEnd = k; break;
                    } 

                    if (idxEnd != -1) {
                        dbg(idxEnd, idxFront);
                        genAns(idxEnd, idxFront);
                        break;
                    }
                }
            }
            dbg(c);
        }

        cout << ans.size() << endl;
        REP(i, ans.size()) {
            if (i == ans.size()) break;
            cout << ans[i].size();
            for(auto num : ans[i]) {
                cout << " " << num;
            }ln;
        }
        
    }
    return 0;
}