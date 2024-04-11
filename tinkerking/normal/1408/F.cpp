#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;
vector<pii>ans;

void merge(vi &v, int L, int R) {
    if (L >= R) return;
    if (L == R - 1) {
        ans.push_back(pii(v[L], v[R]));
        return;
    } 
    int len = R - L + 1;
    int mid = L + len / 2 - 1;
    merge(v, L, mid);
    merge(v, mid + 1, R);
    for (int i=L;i<=mid;i++) {
        ans.push_back(pii(v[i], v[i + len / 2]));
    }
}

int main() {
    int N;
    scanf("%d",&N);
    vvi fuck;
    int now = 1;
    while(now <= N) {
        int step = 1;
        while(now + step * 2 - 1 <= N) {
            step *= 2;
        }
        vi tmp;
        for (int i=now;i<now+step;i++) tmp.push_back(i);
        now += step;
        fuck.push_back(tmp);
    }
    for (auto &tp:fuck) {
        merge(tp, 0, tp.size() - 1);
    }
    now = 1;
    for (int i=int(fuck.size())-2;i>=1;i--) {
        vi &tmp = fuck.back();
        while(tmp.size() < fuck[i].size()) {
            int tsz = tmp.size();
            for (int j=0;j<tsz;j++) {
                ans.push_back(pii(tmp[j], now + j));
                tmp.push_back(now + j);
            }
            now += tsz;
        }
        int sz = tmp.size();
        for (int j=0;j<sz;j++) {
            ans.push_back(pii(tmp[j], fuck[i][j]));
            tmp.push_back(fuck[i][j]);
        }
    }
    printf("%d\n",ans.size());
    for (auto t:ans) {
        printf("%d %d\n",t.first,t.second);
    }
}