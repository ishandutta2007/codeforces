#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int dep;
const int N(27);
int w[N][3];
int (*v)[3];
int infi(2e9);
struct RecDelta {
    int a, deltaB, deltaC, plan;
    RecDelta(int a, int deltaB, int deltaC, int plan) : a(a), deltaB(deltaB), deltaC(deltaC), plan(plan) {
    }
};
vector<RecDelta> * vec;
__inline bool operator < (const RecDelta & a, const RecDelta & b) {
    if(a.deltaB != b.deltaB) {
        return a.deltaB < b.deltaB;
    }
    if(a.deltaC != b.deltaC) {
        return a.deltaC < b.deltaC;
    }
    return false;
}
void dfs(int i, int a, int b, int c, int sol) {
    if(i == dep) {
        //printf("%d %d %d %d\n", a, b, c, sol);
        vec->push_back(RecDelta(a, b - a, c - a, sol));
    }else {
        dfs(i + 1, a + v[i][0], b + v[i][1], c, sol * 3);
        dfs(i + 1, a + v[i][0], b, c + v[i][2], sol * 3 + 1);
        dfs(i + 1, a, b + v[i][1], c + v[i][2], sol * 3 + 2);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i(0); i < n; i++) {
        scanf("%d%d%d", &w[i][0], &w[i][1], &w[i][2]);
    }
    vector<RecDelta> vec1, vec2;
    dep = (n + 1) / 2;
    v = w;
    vec = &vec1;
    dfs(0, 0, 0, 0, 0);
    dep = n / 2;
    v = w + (n + 1) / 2;
    vec = &vec2;
    dfs(0, 0, 0, 0, 0);
    set<RecDelta> st;
    for(int i(0); i < (int)vec2.size(); i++) {
        set<RecDelta>::iterator itr(st.find(vec2[i]));
        if(itr == st.end()) {
            st.insert(vec2[i]);
        }else if(itr->a < vec2[i].a) {
            st.erase(itr);
            st.insert(vec2[i]);
        }
    }
    int plan1, plan2;
    int ans(-infi);
    for(int i(0); i < (int)vec1.size(); i++) {
        set<RecDelta>::iterator itr(st.find(RecDelta(0, -vec1[i].deltaB, -vec1[i].deltaC, 0)));
        if(itr != st.end()) {
            if(ans < itr->a + vec1[i].a) {
                ans = itr->a + vec1[i].a;
                plan1 = vec1[i].plan;
                plan2 = itr->plan;
            }
        }       
    }
    if(ans == -infi) {
        printf("Impossible\n");
        return 0;
    }
    vector<int> p;
    for(int i(0); i < (n + 1) / 2; i++) {
        p.push_back(plan1 % 3);
        plan1 /= 3;
    }
    reverse(p.begin(), p.end());
    for(int i(0); i < n / 2; i++) {
        p.push_back(plan2 % 3);
        plan2 /= 3;
    }
    reverse(p.begin() + (n + 1) / 2, p.end());
    for(int i(0); i < (int)p.size(); i++) {
        printf("%s\n", p[i] == 0 ? "LM" : p[i] == 1 ? "LW" : "MW");
    }
}