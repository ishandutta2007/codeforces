#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

const int N=1e5+100,M=2e5+100;

int n,a[M],b[M],cnt[N];

int hsh(int p,int q)
{
    p=(p+n)%n;
    q=(q+n)%n;
    if(p>q)
        swap(p,q);
    return (p<<30)|q;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>n>>m;
    unordered_set<int> s;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        s.insert(hsh(a[i],b[i]));
        int len=min((a[i]-b[i]+n)%n,(b[i]-a[i]+n)%n);
        cnt[len]++;
    }
    int g=0;
    for(int len=1;len<n;len++)
        if(cnt[len])
            g=__gcd(g,cnt[len]);
    for(int k=1;k<n;k++)
        if(n%k==0&&g*k%n==0||2*k==n)
        {
            unordered_set<int> t;
            for(int i=1;i<=m;i++)
                t.insert(hsh(a[i]+k,b[i]+k));
            if(s==t)
                cout<<"Yes",exit(0);
        }
    cout<<"No";
}