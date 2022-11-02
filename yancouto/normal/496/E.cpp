#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
const int MAX = 100009;
int ps[MAX][2], as[MAX][3];
map<int, int> compr;

vector<int> padd[MAX << 2], aadd[MAX << 2];
multimap<int, pair<int, int> > mp;
int resp[MAX];

int main() {
    int i, n, m;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &ps[i][0], &ps[i][1]);
        compr[ps[i][0]] = 0; compr[ps[i][1]] = 0;
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &as[i][0], &as[i][1], &as[i][2]);
        compr[as[i][0]] = 0; compr[as[i][1]] = 0;
    }
    i = 0;
    for(auto &e : compr)
        e.snd = i++;
    for(i = 0; i < n; i++) {
        ps[i][0] = compr[ps[i][0]];
        ps[i][1] = compr[ps[i][1]];
        padd[ps[i][0]].push_back(i);
    }
    for(i = 0; i < m; i++) {
        as[i][0] = compr[as[i][0]];
        as[i][1] = compr[as[i][1]];
        aadd[as[i][0]].push_back(i);
    }
    for(i = 0; i < compr.size(); i++) {
        while(!mp.empty() && mp.begin()->fst < i) mp.erase(mp.begin());
        for(int v : aadd[i]) mp.insert(make_pair(as[v][1], make_pair(as[v][2], v)));
        for(int v : padd[i]) {
            auto it = mp.lower_bound(ps[v][1]);
            if(it == mp.end()) {
                puts("NO");
                return 0;
            }
            resp[v] = it->snd.snd;
            it->snd.fst--;
            if(it->snd.fst == 0) mp.erase(it);
        }
    }
    puts("YES");
    for(i = 0; i < n; i++)
        printf("%d ", resp[i] + 1);
    putchar('\n');
    return 0;
}