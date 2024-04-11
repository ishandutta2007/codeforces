#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],cnt[N];

bool check(int l,int r)
{
    int len=r-l+1;
    set<int> s;
    for(int i=l;i<=r;i++)
    {
        int x=a[i];
        if(x>len)
            return false;
        if(s.count(x))
            return false;
        s.insert(x);
    }
    return s.size()==len;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        int mx1=0,mx2=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>=2)
                mx2=i;
            if(cnt[i]>=1)
                mx1=i;
        }
        if(mx1+mx2!=n)
        {
            cout<<"0\n";
            continue;
        }
        bool ok1=check(1,mx1)&&check(mx1+1,n);
        bool ok2=check(1,mx2)&&check(mx2+1,n);
        if(!ok1&&!ok2)
            cout<<"0\n";
        else if(mx1==mx2)
            cout<<"1\n"<<mx1<<" "<<mx2<<"\n";
        else if(!ok1)
            cout<<"1\n"<<mx2<<" "<<mx1<<"\n";
        else if(!ok2)
            cout<<"1\n"<<mx1<<" "<<mx2<<"\n";
        else
            cout<<"2\n"<<mx1<<" "<<mx2<<"\n"<<mx2<<" "<<mx1<<"\n";
    }
}