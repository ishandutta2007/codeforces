
#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,k,arr[501];

void query(set<int> &tr) {
    printf("?");
    for(auto &it:tr) printf(" %d",it);
    puts("");
    fflush(stdout);
}

int main() {
    scanf("%d%d",&n,&k);
    if(k==1) {
        puts("! 1");
        fflush(stdout);
        return 0;
    }

    set<int> tr;
    for(int i=1;i<=k;i++) tr.insert(i);

    for(int i=0;i<n-k-1;i++) {
        query(tr);

        int pos,val;
        scanf("%d%d",&pos,&val);
        arr[pos] = val;
        tr.erase(pos);
        tr.insert(k + i + 1);
    }
    
    int v1 = 0, v2 = 0, p1, p2;
    query(tr);
    
    int pos;
    scanf("%d%d",&pos,&v1);
    p1 = pos;
    tr.erase(pos);
    tr.insert(n);
    query(tr);
    scanf("%d%d",&pos,&v2);
    p2 = pos;
    tr.erase(pos);
    if(v1>v2) swap(v1,v2);

    vector<int> ta;
    for(auto &it:tr) ta.push_back(it);

    int ans=1;
    tr.insert(p1);
    tr.insert(p2);
    for(auto &it:ta) {
        tr.erase(it);
        query(tr);
        
        int pos, val;
        scanf("%d%d",&pos,&val);
        if(val == v2) ans++;
        tr.insert(it);
    }
    printf("! %d\n",ans);
    fflush(stdout);

    return 0;
}