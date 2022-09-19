#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector <int> a[n];
        bool used[n];
        int deq[n]={0};
        set <int> unuse;
        for(int i=0;i<(n-1);++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            deq[x]++;deq[y]++;
            a[x].push_back(y);a[y].push_back(x);
            used[x]=false;used[y]=false;
            unuse.insert(x);unuse.insert(y);
        }
        k=min(k,n);
        set <int> nxt;
        for(int i=0;i<n;++i) if(deq[i]<=1) nxt.insert(i);
        for(int cyc=0;cyc<k;++cyc)
        {
            vector <int> z;
            for(auto h:nxt)
            {
                if(!unuse.count(h)) continue;
                if(deq[h]<=1)
                {
                     z.push_back(h);
                     used[h]=true;
                }
            }
            nxt.clear();
            for(auto l:z)
            {
                unuse.erase(l);
                for(auto h1:a[l])
                {
                     if(unuse.count(h1))
                     {
                         if(deq[h1]<=2)
                         {
                             nxt.insert(h1);
                         }
                     }
                     deq[h1]--;
                }
            }
        }
        cout<<unuse.size()<<'\n';
    }
    return 0;
}