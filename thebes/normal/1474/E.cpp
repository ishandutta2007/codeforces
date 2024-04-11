#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int T, N, i, j, arr[MN];
long long ans;
vector<pair<int,int>> op;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ans = 0; op.clear();
        for(i=1;i<=N;i++)
            arr[i] = i;
        for(i=2;i<N;i++){
            if(i-1>=N-i){
                op.push_back({i,1});
                ans += 1LL*(i-1)*(i-1);
            }
            else{
                op.push_back({i,N});
                ans += 1LL*(N-i)*(N-i);
            }
        }
        ans += 1LL*(N-1)*(N-1);
        op.push_back({1,N});
        for(i=N-2;i>=0;i--){
            swap(arr[op[i].first], arr[op[i].second]);
        }
        printf("%lld\n",ans);
        for(i=1;i<=N;i++)
            printf("%d ",arr[i]);
        printf("\n%d\n",(int)op.size());
        for(auto v : op)
            printf("%d %d\n",v.first,v.second);
    }
    return 0;
}