#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ 666666
int n,m; ll t,sf=0;
int s[SZ],ans[SZ]; char d[SZ];
pair<int,int> g[SZ];
pair<pair<int,int>,int> h[SZ];
int main() {
    scanf("%d%d%lld",&n,&m,&t);
    for(int i=0;i<n;++i) {
        scanf("%d%s",s+i,d+i);
        --s[i];
        int k=(d[i]=='R')?1:-1;
        h[i]=make_pair(make_pair(s[i],-k),i);
        g[i]=make_pair(((s[i]+k*t)%m+m)%m,-k);
        sf+=t/m*k%n;
        if(k==1) sf+=(s[i]+t%m>=m);
        else sf-=(s[i]-t%m<=-1);
    }
    sort(g,g+n); sort(h,h+n);
    for(int i=0;i<n;++i)
        ans[h[i].second]=g[(i+sf%n+n)%n].first;
    for(int i=0;i<n;++i)
        printf("%d ",ans[i]+1);
}