#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef double ld;
typedef struct edge{int f, t, v;bool operator<(const edge& e) const{return v < e.v;}}edge;
const int N = 3e5 + 50;
int ans[N];
vector< pi > w;
int main() {
    int n, m, a, b, c;
    vector< edge > v;
    cin >> n >> m;
    for(int i = 0; i < m; i++){cin >> a >> b >> c;edge e = {a, b, c};v.push_back(e);}
    sort(v.begin(), v.end());

    int i = 0, j;
    while( i < v.size()){
        j = i;
        while(j < v.size() && v[j].v == v[i].v){if(ans[v[j].f] + 1 > ans[v[j].t]) w.push_back(pi(v[j].t, ans[v[j].f] + 1));j++;}
        for(int q = 0; q < w.size(); q++){ans[w[q].first] = max(ans[w[q].first], w[q].second);}
        i = j;
        w.clear();
    }
    cout << *max_element(ans, ans + N) << endl;
}