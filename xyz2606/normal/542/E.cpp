#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
 
const int N = 1111;
 
vector<int> edges[N];
bool vst[N];
int infi(1e9);
int n, m, dis[N], ans[N];

pair<int, int> rela[N];

pair<int, int> getr(int x) {
    pair<int, int> p(x, 0), p1, p2;
    while(rela[p.first].first != p.first) {
        p.second ^= rela[p.first].second;
        p.first = rela[p.first].first;
    }
    p1 = p; p = make_pair(x, 0);
    while(rela[p.first].first != p.first) {
        p2.second = p.second ^ rela[p.first].second;
        p2.first = rela[p.first].first;
        rela[p.first].first = p1.first;
        rela[p.first].second = p1.second ^ p.second;
        p = p2;
    }
    return p1;
}

vector<int> q;
int x, d;
void findCnnt(int i) {
    q.clear();
    q.push_back(i);
    vst[i] = true;
    for(int op(0); op < (int)q.size(); op++) {
        int v(q[op]);
        for(int p(0); p != edges[v].size(); p++) {
            int y(edges[v][p]);
            if(!vst[y]) {
                vst[y] = true;
                q.push_back(y);
            }
        }
    }
}

int findFar(int v) {
    for(int i(1); i <= n; i++) {
        dis[i] = infi;
    }
    dis[v] = 0;
    static vector<int> queue;
    queue.clear();
    queue.push_back(v);
    for(int op(0); op < (int)queue.size(); op++) {
        int v(queue[op]);
        //printf("%d\n", v);
        for(int p(0); p != edges[v].size(); p++) {
            int y(edges[v][p]);
            //printf(" %d %d\n", y, dis[y]);
            if(dis[y] == infi) {
            //  printf("!\n");
                dis[y] = dis[v] + 1;
                queue.push_back(y);
            }
        }
    }
//  printf("%d %d %d\n", v, queue.back(), dis[queue.back()]);
    return dis[queue.back()];
    x = queue.back();
    d = dis[x];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= n; i++) {
        rela[i] = make_pair(i, 0);
    }
    bool flag(true);
    for(int i(1); i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        pair<int, int> xx(getr(x)), yy(getr(y));
        if(xx.first == yy.first) {
            if(xx.second == yy.second) {
                flag = false;
                break;
            }
        }else {
            rela[xx.first] = make_pair(yy.first, 1 ^ xx.second ^ yy.second);
        }
    }
    if(!flag) {
        printf("-1\n"); 
    }else {
        for(int i(1); i <= n; i++) {
            fill(dis + 1, dis + 1 + n, infi);
            ans[getr(i).first] = max(ans[getr(i).first], findFar(i));
        }
        int tot(0);
        for(int i(1); i <= n; i++) {
            if(rela[i].first == i) {
                tot += ans[i];
            }
        }
        printf("%d\n", tot);
    }
}