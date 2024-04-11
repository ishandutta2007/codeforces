#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    int cur=1,mult=1;
    while(s.size()>1)
    {
        int cnt2=0,cnt3=0;
        for(int x:s)
        {
            if(x%2==0)
                cnt2++;
            if(x%3==0)
                cnt3++;
        }
        set<int> t;
        if(cnt3>=cnt2)
        {
            for(int x:s)
                if(x%3==0)
                    t.insert(x);
                else
                    cout<<cur<<" ";
        }
        else
        {
            for(int x:s)
                if(x%2==0)
                    t.insert(x);
                else
                    cout<<cur<<" ";
        }
        cur=0;
        for(int x:t)
            cur=__gcd(cur,x);
        s.clear();
        for(int x:t)
            s.insert(x/cur);
        mult=cur=mult*cur;
    }
    cout<<cur<<" ";
}