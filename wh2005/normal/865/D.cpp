#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+9;
int n,a[N];
priority_queue<int >q;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    while(!q.empty()) q.pop();
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!q.empty()&&-q.top()<a[i]){
            ans+=(a[i]+q.top());
            q.pop();q.push(-a[i]);
        }
        q.push(-a[i]);
    }    
    printf("%lld\n",ans);
    return 0;
}