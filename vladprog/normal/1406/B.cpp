#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e18;

int check(int prod,int cnt,vector<int>::iterator pos,vector<int>::iterator last)
{
    if(cnt==5)
        return prod;
    if(pos==last)
        return -INF;
    return max(check(prod,cnt,pos+1,last),
               check(prod**pos,cnt+1,pos+1,last));
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
        vector<int> v;
        while(n--)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        if(v.size()>10)
            v.erase(v.begin()+5,v.end()-5);
        cout<<check(1,0,v.begin(),v.end())<<"\n";
    }
}