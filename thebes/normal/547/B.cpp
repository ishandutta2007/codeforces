#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5;
int arr[MN], ord[MN], n, i, x, lst, ans[MN];
multiset<int> len;
set<int> pos;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        ord[i] = i;
    }
    sort(ord+1,ord+n+1,[](int i,int j){return arr[i]<arr[j];});
    pos.insert(0), pos.insert(n+1);
    len.insert(n);
    lst = n;
    for(i=1;i<=n;i++){
        int p = ord[i];
        auto nxt = pos.lower_bound(p);
        auto pre = nxt; pre --;
        len.erase(len.find(*nxt-*pre-1));
        len.insert(p-*pre-1);
        len.insert(*nxt-p-1);
        pos.insert(p);
        auto mx = len.end(); mx--;
        while(lst>*mx) ans[lst--]=arr[p];
    }
    for(i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}