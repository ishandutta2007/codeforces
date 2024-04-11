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
    map< pii , vector<int> > s;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        s[pair(l-1,-1)].push_back(i+1);
        s[pair(r+1,-2)].push_back(i+1);
    }
    set<int>t;
    int k=0;
    for(pair<pii, vector<int> > p:s)
        if(p.first.second==-1)
        {
            k+=p.second.size();
            if(k>1)
                t.insert(p.second.begin(),p.second.end());
        }
        else
        {
            for(int x:p.second)
                if(k>1&&t.count(x))
                    cout<<x,exit(0);
            k-=p.second.size();
            if(k<=1)
                t.clear();
        }
    cout<<-1;
}