#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()

void print(vector<int> v) {
    cout << sz(v) << "\n";
    for(int x : v) cout << x << " ";
    cout << "\n";
}

void print_ans(vector<int> a, vector<int> b, bool swp) {
    if(swp) swap(a, b);
    print(a);
    print(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> A(n), B(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }
    vector<long long> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = a[i - 1] + A[i - 1], b[i] = b[i - 1] + B[i - 1];
    bool swp = false;
    if(b[n] < a[n])
        swap(a, b), swp = true;
    vector<int> aa, bb;
    vector<int> nxt(n + 1);
    nxt[n] = n;
    int j = n;
    vector<pair<int, int>> sto(n);
    for(int i = 0; i < n; i++)
        sto[i] = {-1, -1};
    for(int i = n; i >= 0; i--) {
        while(j >= 0 && b[j] >= a[i])
            --j;
        nxt[i] = j + 1;
        if(b[nxt[i]] == a[i]) {
            for(int x = 1; x <= i; x++)
                aa.push_back(x);
            for(int x = 1; x <= nxt[i]; x++)
                bb.push_back(x);
            print_ans(aa, bb, swp);
            return 0;
        }
        if(sto[b[nxt[i]] - a[i]] == make_pair(-1, -1)) {
            sto[b[nxt[i]] - a[i]] = {i, nxt[i]};
        }
        else {
            pair<int, int> lookup = sto[b[nxt[i]] - a[i]];
            for(int x = i + 1; x <= lookup.first; x++)
                aa.push_back(x);
            for(int x = nxt[i] + 1; x <= lookup.second; x++)
                bb.push_back(x);
            print_ans(aa, bb, swp);
            return 0;
        }
    }
    
}