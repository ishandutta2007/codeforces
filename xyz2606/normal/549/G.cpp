#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > vec;
    for(int i(0); i < n; i++) {
        int x;
        scanf("%d", &x);
        vec.push_back(make_pair(x + i, i));
    }
    bool flag(true);
    sort(vec.begin(), vec.end());
    for(int i(0); i < n; i++) {
        if(i && vec[i].first == vec[i - 1].first) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        printf(":(\n");
    }else {
        for(int i(0); i < n; i++) {
            printf("%d%c", vec[i].first - i, i == n - 1?'\n':' ');
        }
    }
}