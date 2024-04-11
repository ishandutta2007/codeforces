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
vector<int> st1, st2;
int n, m, color[11111];
vector<int> edges[11111];
int code(int i, int j) {
    return (i) * m + j + 1;
}
vector<pair<int, int> > st0;
void psh(int v) {
    st0.push_back(make_pair(v, 0));
    st1.push_back(v);
    color[v] = st1.size();
    st2.push_back(v);
}
char st[1111];
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", st);
    for(int i(0); i < n; i++) {
        if(st[i] == '<') {
            for(int j(1); j < m; j++) {
                edges[code(i, j)].push_back(code(i, j - 1));
            }
        }else {
            for(int j(0); j < m - 1; j++) {
                edges[code(i, j)].push_back(code(i, j + 1));
            }
        }
    }
    scanf("%s", st);
    for(int i(0); i < m; i++) {
        if(st[i] == '^') {
            for(int j(1); j < n; j++){
                edges[code(j, i)].push_back(code(j - 1, i));
            
            }
        }else {
            for(int j(0); j < n - 1; j++){
                edges[code(j, i)].push_back(code(j + 1, i));
            }
        }
    }
    n = n * m;
    int c(n);
    fill(color + 1, color + 1 + n, 0);
    for(int i(1); i <= n; i++) if(!color[i]) {
        psh(i);
        while(!st0.empty()) {
            int v(st0.back().first), p(st0.back().second++);
            if(p != (int)edges[v].size()) {
                int y(edges[v][p]);
                if(!color[y]) {
                    psh(y);
                }else
                    while(!st2.empty() and color[st2.back()] > color[y])
                        st2.pop_back();
            }else {
                st0.pop_back();
                if(st2.back() == v) {
                    st2.pop_back();
                    color[v] = ++c;
                    while(st1.back() != v) {
                        color[st1.back()] = c;
                        st1.pop_back();
                    }
                    st1.pop_back();
                }
            }
        }
    }
    if(c > n + 1)
        printf("NO\n");
    else printf("YES\n");
    return 0;
}