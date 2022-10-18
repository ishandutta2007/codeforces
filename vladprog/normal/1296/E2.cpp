#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    set<pair<char,int>> last;
    for(int i=0;i<n;i++)
    {
        auto it=last.upper_bound({s[i],1e9});
        if(it==last.begin())
            c[i]=last.size()+1;
        else
            it--,
            c[i]=it->y,
            last.erase(it);
        last.insert({s[i],c[i]});
    }
    cout<<last.size()<<"\n";
    for(int i=0;i<n;i++)
        cout<<c[i]<<" ";
}