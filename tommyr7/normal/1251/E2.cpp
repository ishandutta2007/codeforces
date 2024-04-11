#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int T,n;
pair<int,int> a[Maxn];
multiset<int> s;
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    s.clear();
    long long ans=0LL;
    int tmp=0;
    for (int i=n;i;i--)
    {
        s.insert(a[i].second);
        while (tmp<max(0,a[i].first-i+1))
        {
            ++tmp;
            multiset<int>::iterator it=s.begin();
            ans+=(*it);
            s.erase(it);
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}