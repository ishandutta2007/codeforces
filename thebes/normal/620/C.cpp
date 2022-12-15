#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int MN = 1e5+5;
int N, lst=1, i, x; set<int> s;
vector<pii> ans;

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d",&x);
        if(s.count(x)){
            ans.push_back({lst,i});
            lst = i+1;
            s.clear();
        }
        else s.insert(x);
    }
    if(lst!=N+1&&ans.empty()) printf("-1\n");
    else{
        ans.back().second = N;
        printf("%d\n",ans.size());
        for(auto v : ans) printf("%d %d\n",v.first,v.second);
    }
    return 0;
}