#include <bits/stdc++.h>

using namespace std;


int mark[10];
int pos[10];
int c, t, tol;
vector<string> callNext(vector<int> v) {
 /*   tol--;
    if (tol < 0) assert(0);
   */ 
    cout << "next ";
    for(auto i : v) cout << i << " ";
    cout << endl;
/*
    for(auto i : v) {
        pos[i]++;
        if (pos[i] == t + c) pos[i] = t;
    }*/
    vector<string> ans;
/*
    memset(mark, 0, sizeof(mark));
    for(int st = 0; st < 10; st++) if (!mark[st]) {
        string s;
        for(int i = 0; i < 10; i++) if (pos[i] == pos[st]) {
            s.push_back(i + '0');
            mark[i] = 1;
        }
        ans.push_back(s);
    }*/

    int k;
    cin >> k;
    while (k--) {
        string s;
        cin >> s;
        ans.push_back(s);
    }
    return ans;
}
void phase1() {
    while (1) {
        callNext({0, 1});
        vector<string> use = callNext({1});
        if (use.size() == 2) break;
    }
}
int h[10];
bool check2(vector<string> &a) {
    for(auto i : a) {
        int mask = 0;
        for(auto j : i) mask |= 1 << (j - '0');
        if ((mask & 1021) == 1021) return 1;
    }
    return 0;
}
void phase2() {
    while (1) {
        vector<string> use = callNext({0, 2, 3, 4, 5, 6, 7, 8, 9});
        if (check2(use)) break; 
    }
}
void phase3() {
    while (1) {
        vector<string> use = callNext({1});
        if (use.size() == 1) break;
    }
    cout << "done" << endl;
    assert(count(pos, pos + 10, t) == 10);
}
bool checkRun(int cc, int ct) {
    
    cout << "Test " << cc << " " << ct << '\n';
    c = cc, t = ct;
    tol = 3 * (c + t);
    memset(pos, 0, sizeof(pos));
    phase1();
    phase2();
    phase3();
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

/*
    for(int cc = 1; cc <= 1000; cc++) {
        for(int ct = 1; ct <= 1000; ct++) {
            checkRun(cc, ct);
        }
    }*/
    phase1();
    phase2();
    phase3();
}