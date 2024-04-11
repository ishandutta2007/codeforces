#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N(211111);
typedef pair<pair<long long, long long>, int> Record;
long long l[N], r[N];
int ans[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= n; i++) {
        scanf("%I64d%I64d", &l[i], &r[i]);
    }
    vector<Record> vec;
    for(int i(1); i < n; i++) {
        vec.push_back(make_pair(make_pair(l[i + 1] - r[i], r[i + 1] - l[i]), i));
    }
    sort(vec.begin(), vec.end());
    priority_queue<Record, vector<Record>, greater<Record> > pq;
    vector<pair<long long, int> > bridges;
    for(int i(1); i <= m; i++) {
        long long x;
        scanf("%I64d", &x);
        bridges.push_back(make_pair(x, i));
    }
    sort(bridges.begin(), bridges.end());
    int j(0);
    for(int i(0); i < (int)bridges.size(); i++) {
        while(j < (int)vec.size() && vec[j].first.first <= bridges[i].first) {
            vec[j].first.first = 0;
            pq.push(vec[j]);
            j++;
        }
        if(!pq.empty() && pq.top().first.second >= bridges[i].first) {
            ans[pq.top().second] = bridges[i].second;
            pq.pop();
        }
    }
    bool flag(true);
    for(int i(1); i < n; i++) {
        if(ans[i] == 0) {
            flag = false;
            break;
        }
    }
    if(flag) {
        printf("Yes\n");
        for(int i(1); i < n; i++) {
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
        }
    }else {
        printf("No\n");
    }
}