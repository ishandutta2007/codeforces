using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 35

int T,owo[26],qwq[26];

string a,b;

void solve() {
    cin >> a >> b;
    memset(owo,0,sizeof(owo));
    memset(qwq,0,sizeof(qwq));
    vector<int> v;

    for(int i = 0;i < b.size();++i) {
        owo[b[i] - 'A']++;
    }

    for(int i = a.size() - 1;i >= 0;--i) {
        if(qwq[a[i] - 'A'] >= owo[a[i] - 'A']) continue;
        v.push_back(i);
        qwq[a[i] - 'A']++;
    }

    sort(v.begin(),v.end());

    string s;

    for(int i : v) {
        s += a[i];
    }

    cout << (b == s ? "YES" : "NO") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) solve();
    return 0;
}