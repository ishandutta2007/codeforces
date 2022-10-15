#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
const int N(100001);
vector<pair<int, int> > edges[N], querys;
pair<int, int> mapTo[N];
int rela[N], re[333][N], ans[N];
int getr(int * rela, int x) {
    int p(x), p1, p2;
    while(p != rela[p]) {
        p = rela[p];
    }
    p1 = p; p = x;
    while(p != rela[p]) {
        p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[z].push_back(make_pair(x, y));
    }
    int nq;
    scanf("%d", &nq);
    for(int i(1); i <= nq; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > y) {
            swap(x, y);
        }
        querys.push_back(make_pair(x, y));
        mapTo[i] = make_pair(x, y);
    }
    sort(querys.begin(), querys.end());
    querys.resize(unique(querys.begin(), querys.end()) - querys.begin());
    int LIM(sqrt(N));
    int cnt(0);
    for(int i(1); i <= m; i++) {
        if(edges[i].size() <= LIM) {
            static vector<int> vec;
            vec.clear();
            for(int j(0); j < (int)edges[i].size(); j++) {
                vec.push_back(edges[i][j].first);
                vec.push_back(edges[i][j].second);
            }
            sort(vec.begin(), vec.end());
            vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
            for(int j(0); j < (int)vec.size(); j++) {
                rela[vec[j]] = vec[j];
            }
            for(int j(0); j < (int)edges[i].size(); j++) {
                if(getr(rela, edges[i][j].first) != getr(rela, edges[i][j].second)) {
                    rela[getr(rela, edges[i][j].first)] = getr(rela, edges[i][j].second);
                }
            }
            for(int j(0); j < (int)vec.size(); j++) {
                for(int k(j + 1); k < (int)vec.size(); k++) if(getr(rela, vec[j]) == getr(rela, vec[k])) {
                    int p(lower_bound(querys.begin(), querys.end(), make_pair(vec[j], vec[k])) - querys.begin());
                    if(p != (int)querys.size() and vec[j] == querys[p].first and vec[k] == querys[p].second) {
                        ans[p]++;   
                    }
                }
            }
        }else {
            cnt++;
            for(int j(1); j <= n; j++) {
                re[cnt][j] = j;
            }
            for(int j(0); j < (int)edges[i].size(); j++) {
                if(getr(re[cnt], edges[i][j].first) != getr(re[cnt], edges[i][j].second)) {
                    re[cnt][getr(re[cnt], edges[i][j].first)] = getr(re[cnt], edges[i][j].second);
                }
            }
            
        }
    }
    for(int i(1); i <= nq; i++) {
        int p(lower_bound(querys.begin(), querys.end(), mapTo[i]) - querys.begin());
        int x(querys[p].first), y(querys[p].second), tmp(ans[p]);
        for(int j(1); j <= cnt; j++) {
            if(getr(re[j], x) == getr(re[j], y)) {
                tmp++;
            }
        }
        printf("%d\n", tmp);
    }
    fclose(stdin);
    return 0;
}