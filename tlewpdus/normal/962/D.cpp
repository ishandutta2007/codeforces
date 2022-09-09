#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
set<pll> s;
vector<pll> vec;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        s.insert(pll(a,i));
    }
    auto it = s.begin();
    while(1) {
        it = s.begin();
        if (it==s.end()) break;
        pll a = *it;
        it++;
        if (it==s.end()) {
            vec.push_back(a);
            break;
        }
        pll b = *it;
        if (a.first==b.first) {
            s.erase(s.begin());
            s.erase(s.begin());
            s.insert(pll(a.first*2,b.second));
        }
        else {
            s.erase(s.begin());
            vec.push_back(a);
        }
    }
    sort(vec.begin(),vec.end(),[](pll a, pll b){return a.second<b.second;});
    printf("%d\n",vec.size());
    for (pll &v:vec) {
        printf("%lld ",v.first);
    }
    printf("\n");

    return 0;
}