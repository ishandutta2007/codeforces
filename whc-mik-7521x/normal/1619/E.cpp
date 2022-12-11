#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
signed main(){
    scanf("%lld",&t);
    while(t--){
        int cnt[200005];
        scanf("%lld",&n);
        for(int i=0;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%lld",&x);
            cnt[x]++;
        }
        printf("%lld ",cnt[0]);
        stack<int>s;
        int now=0,i;
        for(i=1;i<=n;i++){
            for(int o=0;o<cnt[i-1];o++)s.push(i-1);
            if(!s.size())break;
            now+=i-1-s.top(),s.pop();
            printf("%lld ",(int)(cnt[i]+now));
        }
        for(;i<=n;i++)printf("-1 ");
        puts("");
    }
    return  0;
}