#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long b[100001];
queue<long long> x[60];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)scanf("%lld", b+i);
    sort(b+1, b+n+1);
    int k = 1;
    for(int i=1; i<=n; i++){
        while(b[i] >= (1ll<<k)) k++;
        x[k-1].push(b[i]);
    }
    long long now = 0, t;
    vector<long long> ans;
    for(int i=1; i<=n; i++){
        for(int k=0; k<60; k++){
            if(x[k].empty() || ((now>>k)&1) == 1) continue;
            t = x[k].front(); x[k].pop();
            now ^= t;
            ans.push_back(t);
            goto next;
        }
        printf("No\n");
        return 0;
        next:;
    }
    printf("Yes\n");
    for(auto t: ans) printf("%lld ", t);
    printf("\n");
    return 0;
}