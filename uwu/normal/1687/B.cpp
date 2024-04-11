#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> a(M);
    string s(M, '0');
    for (int i = 0; i < M; ++i){
        s[i] = '1';
        cout << "? " << s << '\n';
        cout.flush();
        cin >> a[i];
        s[i] = '0';
    }
    vector<int> idx(M);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    int mst = 0;
    for (int j = 0; j < M; ++j){
        int i = idx[j];
        s[i] = '1';
        cout << "? " << s << '\n';
        cout.flush();
        int nxt; cin >> nxt;
        if (nxt != mst + a[i]) s[i] = '0';
        else mst = nxt; 
    }
    cout << "! " << mst << '\n';
    cout.flush();
}