#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 2e5+5;
ll ans, N, K, arr[MN], i, j, k;
priority_queue<ll> q;
string s;

int main(){
    for(scanf("%lld%lld",&N,&K),i=1;i<=N;i++)
        scanf("%lld",&arr[i]);
    cin >> s;
    s.insert(s.begin(),' ');
    s.push_back(' ');
    for(i=N;i>=1;i--){
        if(s[i]!=s[i+1]){
            k = K;
            while(q.size()&&(k--)){
                ans += q.top();
                q.pop();
            }
            while(q.size()) q.pop();
            q.push(arr[i]);
        }
        else q.push(arr[i]);
    }
    k = K;
    while(q.size()&&(k--)){
        ans += q.top();
        q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}