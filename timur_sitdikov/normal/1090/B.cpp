#include <bits/stdc++.h>

#define Pi acos(-1.)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define fi first
#define se second
#define FILE "474"
#define standart 1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e9 + 322;
const ll LINF = 2e18 + 474;
const ll MAXN = 2e5 + 500;
const double eps = 1e-12;

int n;
char a[MAXN];
vector<string> x, y;
map<string, int> ind;
map<string, string> str;
void solve() {
    while(true) {
        char c = getchar();
        a[n++] = c;
        if(c == EOF)
            break;
    }
    int top = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i] == '\\' && a[i+1] == 'c' && a[i+2] == 'i'
           && a[i+3] == 't' && a[i+4] == 'e') {
                int j = i + 6;
                string tmp = "";
                while(a[j] != '}') {
                    tmp+=a[j];
                    j++;
                }
                x.pb(tmp);
                //cout << tmp << " ";
           }
        else if(a[i] == '\\' && a[i+1] == 'b' && a[i+2] == 'i' && a[i+3] == 'b'
                && a[i+4] == 'i' && a[i+5] == 't' && a[i+6] == 'e' && a[i+7] == 'm') {
                    int j = i + 9;
                    string tmp = "";
                    while(a[j] != '}') {
                        tmp+=a[j];
                        j++;
                    }
                    ind[tmp] = top++;
                    j = i;
                    string tmp1 = "";
                    while(a[j] != '\n') {
                        tmp1 +=a[j];
                        j++;
                    }
                    str[tmp] = tmp1;
                }
    }
    bool ok = true;
    for(int i = 0; i < x.size(); i++) {
        if(ind[x[i]] != i) {
            ok = false;
        }
    }
    if(ok) {
        cout << "Correct";
        return;
    }
    cout << "Incorrect\n";
    cout << "\\begin{thebibliography}{99}\n";
    for(int i = 0; i < x.size(); i++) {
        cout << str[x[i]] << "\n";
    }
    cout << "\\end{thebibliography}\n";
}



int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int T = 1; //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}