#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

string s;
int a[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    cin >> s;
    a[0] = 0;
    string t = "";
    t.push_back(s[0]);
    int n = s.length();
    for (int i = 1; i < n; i++){
        string tt = s.substr(i, 1) + t;
        t.push_back(s[i]);
        if (t <= tt) {
            a[i] = 0;
        }
        else {
            a[i] = 1;
            a[i - 1] = 1 - a[i - 1];
            t.swap(tt);
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], " \n"[i + 1 == n]);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}