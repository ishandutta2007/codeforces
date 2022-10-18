#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int cnt(int val,int pr)
{
    int res=0;
    while(val%pr==0)
        val/=pr,
        res++;
    return res;
}

int pw(int x,int y)
{
    int res=1;
    while(y--)
        res*=x;
    return res;
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
        int p,q;
        cin>>p>>q;
        if(p%q)
        {
            cout<<p<<"\n";
            continue;
        }
        vector<int> pr;
        int temp=q;
        for(int i=2;i*i<=temp;i++)
            if(temp%i==0)
            {
                pr.push_back(i);
                while(temp%i==0)
                    temp/=i;
            }
        if(temp>1)
            pr.push_back(temp);
        int ans=0;
        for(int a:pr)
        {
            int b=cnt(p,a);
            int c=cnt(q,a);
//            cout<<a<<" -> "<<b<<" "<<c<<" "<<b-c+1<<" "<<pw(a,b-c+1)<<" "<<p/pw(a,b-c+1)<<"\n";
            ans=max(ans,p/pw(a,b-c+1));
        }
        cout<<ans<<"\n";
    }
}