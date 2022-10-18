#include<bits/stdc++.h>

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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> pos[2];
        for(int i=1;i<=2*n;i++)
        {
            int a;
            cin>>a;
            pos[a%2].push_back(i);
        }
        if(pos[0].size()%2)
            pos[0].pop_back(),
            pos[1].pop_back();
        else if(pos[0].empty())
            pos[1].pop_back(),
            pos[1].pop_back();
        else
            pos[0].pop_back(),
            pos[0].pop_back();
        for(int par=0;par<2;par++)
            while(!pos[par].empty())
                cout<<pos[par].back()<<" ",
                pos[par].pop_back();
        cout<<"\n";
    }
}