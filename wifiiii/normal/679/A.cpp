#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int ask(int x) {
    cout << x << endl;
    string s;
    cin >> s;
    if(s == "yes") return 1;
    return 0;
}
int isprime(int x) {
    if(x < 1) return 0;
    for(int i = 2; i * i <= x; ++i) if(x % i == 0) return 0;
    return 1;
}
int main() {
    vector<int> a{2, 3, 5, 7};
    vector<int> ret(a.size());
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        ret[i] = ask(a[i]);
        if(ret[i]) ++cnt;
    }
    if(cnt >= 2) {
        cout << "composite" << endl;
        return 0;
    }
    if(cnt == 0) {
        cout << "prime" << endl;
        return 0;
    }
    int k = 0;
    while(!ret[k]) ++k;
    for(int i = 2; i * a[k] <= 100; ++i) {
        if(!isprime(i)) continue;
        int r = ask(i * a[k]);
        if(r) {
            cout << "composite" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;
}