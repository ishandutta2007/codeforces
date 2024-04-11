#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, T, i, j, a[MN], b[MN], lnk[MN], v[MN];
vector<int> vec;

int dfs(int n, int st){
    v[n] = 1;
    if(n==st) return 0;
    return 1 + dfs(lnk[n], st);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        vec.clear();
        for(i=1;i<=N;i++) scanf("%d",&a[i]);
        for(i=1;i<=N;i++) scanf("%d",&b[i]);
        for(i=1;i<=N;i++) v[i] = 0;
        for(i=1;i<=N;i++) lnk[a[i]] = b[i];
        for(i=1;i<=N;i++){
            if(v[i]) continue;
            vec.push_back(1 + dfs(lnk[i], i));
        }
        sort(vec.begin(), vec.end(), [](int i, int j){return i>j;});
        int l = 1, r = N;
        long long ans = 0;
        for(auto &v : vec){
            if(v&1) v--;
            if(v > 0){
                for(i=1;i<=v;i+=2){
                    ans += 2 * (r- l);
                    l ++; r --;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}