#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll arr[100100];
list<ll> lis;
vector<ll> tmp;

int main() {
    int i, b;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&arr[i]);
    for (b=59;b>=0;b--) {
        int c = 0;
        for (i=0;i<n;i++) {
            if ((arr[i]>>b)&1) {
                tmp.push_back(arr[i]);
                arr[i] = 0;
                c++;
            }
        }
        if (!c) continue;
        auto it = lis.begin();
        int d = 1;
        lis.insert(lis.begin(),tmp.back()); tmp.pop_back();
        while(it!=lis.end()) {
            if (tmp.empty()) break;
            if (((*it)>>b)&1) {
                it++;
                lis.insert(it,tmp.back()); tmp.pop_back();
                d++;
            }
            else it++;
        }
        if (!tmp.empty()){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    auto it = lis.begin();
    while(it!=lis.end()) {
        printf("%lld ",*it);
        it++;
    }

    return 0;
}