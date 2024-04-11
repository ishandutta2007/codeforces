#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=5e5+10;

priority_queue <ii> q;
int n,k;
int a[N],ans[N];

void solve(){
    ll answ=0,sum=0;
    for(int i=1;i<=k;i++) {
        q.push(ii(a[i],i));
        sum+=a[i];
        answ+=sum;
    }
    for(int i=1;i<=n;i++){
        if (i+k<=n) {
            q.push(ii(a[i+k],i+k));
            sum+=a[i+k];
        }
        sum-=q.top().X;
        answ+=sum;
        ans[q.top().Y]=i+k;
        q.pop();
    }
    cout<<answ<<'\n';
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    solve();
}