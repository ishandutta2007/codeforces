#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf=1e14;
const int N=800;
ll f[N];
int n;
int a[N];

priority_queue <int> q;

int check(ll val){
    while (!q.empty()) q.pop();
    int ans=0;
    for(int i=1;i<=n;i++){
        q.push(-a[i]);
        if (val+a[i]<0){
            ans++;
            val+=q.top();
            q.pop();
        }
        val+=a[i];
    }
    return ans;
}
void prepare(){
    int test;
    scanf("%d%d",&n,&test);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int use=0;use<=n;use++){
        ll L=0,R=inf;
        while (L<=R){
            ll mid=(L+R)/2;
            if (check(mid)>use) L=mid+1;
            else R=mid-1;
        }
        f[use]=L;
    }
    while (test--){
        ll val;
        scanf("%lld",&val);
        printf("%d\n",lower_bound(f,f+n+1,val,greater<ll>())-f);
    }
}
int main(){
    prepare();
}