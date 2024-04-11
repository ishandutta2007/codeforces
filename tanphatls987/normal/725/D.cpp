#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

typedef unsigned long long ull;

const int N=3e5+10;


priority_queue <ll> pq;
int n;
ll a[N],w[N];
int p[N];
bool comp(int x,int y){
    if (a[x]==a[y]) return x<y;
    return a[x]>a[y];

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",a+i,w+i);
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,comp);
    int st=1;
    while (p[st]!=1) {
        pq.push(-(w[p[st]]-a[p[st]]+1));
        st++;
    }
    int ans=st;
    st++;
    int drop=0;
    while (!pq.empty()){
        ll cur=pq.top();pq.pop();
        if (a[1]+cur<0) break;
        a[1]+=cur;
        drop++;
        while (st<=n&&a[p[st]]>a[1]) {
            pq.push(-(w[p[st]]-a[p[st]]+1));
            st++;
        }
//        cout<<st<<" "<<drop<<" "<<a[1]<<'\n';
        ans=min(ans,st-1-drop);
    }
    cout<<ans;
}