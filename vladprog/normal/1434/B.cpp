#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

char tp[2*N];
int cost[2*N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> inds;
    for(int i=1;i<=2*n;i++)
    {
        cin>>tp[i];
        if(tp[i]=='+')
            inds.push_back(i);
        else if(inds.empty())
            cout<<"NO",exit(0);
        else
        {
            cin>>cost[i];
            cost[inds.back()]=cost[i];
            inds.pop_back();
        }
    }
    set<int> cur;
    for(int i=1;i<=2*n;i++)
        if(tp[i]=='+')
            cur.insert(cost[i]);
        else if(cur.empty())
            cout<<"NO",exit(0);
        else if(*cur.begin()!=cost[i])
            cout<<"NO",exit(0);
        else
            cur.erase(cur.begin());
    cout<<"YES\n";
    for(int i=1;i<=2*n;i++)
        if(tp[i]=='+')
            cout<<cost[i]<<" ";
}