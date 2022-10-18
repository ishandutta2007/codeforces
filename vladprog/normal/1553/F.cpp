#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int a[N];

struct fenwick
{
    ll t[N+1];
    ll total=0;
    ll operator()(int r)
    {
//        if(r==N)
//            return total;
        ll result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            result += t[r];
        return result;
    }
    void inc(int i, int delta)
    {
        total+=delta;
        for (; i <= N; i = (i | (i+1)))
            t[i] += delta;
    }
    ll operator()(int l, int r)
    {
        return operator()(r) - operator()(l-1);
    }
} sum,cnt;

void upd(int i)
{
    sum.inc(i,i);
    cnt.inc(i,1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
//    n=200000;
    for(int i=1;i<=n;i++)
        cin>>a[i];
//        a[i]=(rand()*(RAND_MAX+1)+rand())%300000+1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=sum.total;
        for(int l=a[i];l<=N;l+=a[i])
            ans-=(cnt.total-cnt(l-1))*a[i];
        ans+=cnt.total*a[i];
        int div=1,prv=0;
        while(true)
        {
            int l=a[i]/(div+1)+1,
                r=a[i]/div;
            ans-=sum(r)*(div-prv);
            if(l<=1)
                break;
            prv=div;
            div=a[i]/(l-1);
        }
        upd(a[i]);
        cout<<ans<<" ";
    }
//    cout<<ans;
}