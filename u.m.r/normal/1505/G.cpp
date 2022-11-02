#include<bits/stdc++.h>
#define Q(s,t) (s[t]=='1')

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

void solve(int casi){
    vector<string> f({"100000", "101000", "110000", "110100", "100100", "111000", "111100", "101100", "011000", "011100", "100010", "101010", "110010", "110110", "100110", "111010", "111110", "101110", "011010", "011110", "100011", "101011", "011101", "110011", "110111", "100111"});
    vector<vector<int>> g;
    for (auto &s : f) {
        vector<int> v;
        v.push_back(Q(s,0)+Q(s,1));
        v.push_back(Q(s,2)+Q(s,3));
        v.push_back(Q(s,4)+Q(s,5));
        v.push_back(Q(s,0)+Q(s,2)+Q(s,4));
        v.push_back(Q(s,1)+Q(s,3)+Q(s,5));
        g.push_back(v);
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        vector<int> v(5, 0);
        for (int j = 0; j < 5; j++) scanf("%d", &v[j]);
        for (int j = 0; j < 26; j++) if (g[j] == v) {
            putchar('a' + j); break;
        }
    }
    puts("");
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}