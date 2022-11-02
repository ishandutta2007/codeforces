#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for(auto&a:(x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

void run() {
    string line;
    getline(cin, line);

    bool f = 0, r = 0;

    if (sz(line) >= 5) {
        f = (line.substr(sz(line)-5) == "lala.");
        r = (line.substr(0, 5) == "miao.");
    }

    if (f && !r) {
        cout << "Freda's\n";
    } else if (!f && r) {
        cout << "Rainbow's\n";
    } else {
        cout << "OMG>.< I don't know!\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    int n; cin >> n;
    string line;
    getline(cin, line);
    while (n--) run();
    return 0;
}