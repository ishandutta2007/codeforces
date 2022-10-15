
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(222222);
int a[N], posi[N];
vector<pair<int, int> > vec;
bool cmp(const pair<int, int> & a, const pair<int, int> & b) {
    return a.first < b.first;
}
int toRight(vector<pair<int, int> >::iterator itr, int &len);
int toLeft(vector<pair<int, int> >::iterator itr, int &len) {
    vector<pair<int, int> >::iterator itr1(lower_bound(vec.begin(), vec.end(), make_pair(itr->first - len, 1), cmp));
    int delta(itr->first - itr1->first);
    if(delta == 0) {
        return itr->second;
    }
    len = len % (2ll * delta);
    if(len < delta) {
        vector<pair<int, int> >::iterator itr2(lower_bound(vec.begin(), vec.end(), make_pair(itr->first - len, 1), cmp));
        len -= (itr->first - itr2->first);
        return toRight(itr2, len);
    }else {
        len -= (itr->first - itr1->first);
        return toRight(itr1, len);
    }
}
int toRight(vector<pair<int, int> >::iterator itr, int &len) {
    vector<pair<int, int> >::iterator itr1(upper_bound(vec.begin(), vec.end(), make_pair(itr->first + len, 1), cmp) - 1);
    int delta(itr1->first - itr->first);
    if(delta == 0) {
        return itr->second;
    }
    len = len % (2ll * delta);
    if(len < delta) {
        vector<pair<int, int> >::iterator itr2(upper_bound(vec.begin(), vec.end(), make_pair(itr->first + len, 1), cmp) - 1);
        len -= (itr2->first - itr->first);
        return toLeft(itr2, len);
    }else {
        len -= (itr1->first - itr->first);
        return toLeft(itr1, len);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= n; i++) {
        scanf("%d", &a[i]);
        vec.push_back(make_pair(a[i], i));
    }
    sort(vec.begin(), vec.end());
    for(int i(0); i < n; i++) {
        posi[vec[i].second] = i;
    }
    for(int i(1); i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(vec.back().first - vec[posi[x]].first >= y) {
            vector<pair<int, int> >::iterator itr(upper_bound(vec.begin(), vec.end(), make_pair(vec[posi[x]].first + y, 1), cmp) - 1);

            printf("%d\n", toLeft(itr, y -= (itr->first - a[x])));
        }else {
            printf("%d\n", toLeft(vec.end() - 1, y -= (vec.back().first - a[x])));
        }
    }
}