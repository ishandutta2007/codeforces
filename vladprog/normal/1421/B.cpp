#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=210;

string s[N];

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
        for(int i=0;i<n;i++)
            cin>>s[i];
        char a='0',b='1';
        if((s[0][1]!=a)+
           (s[1][0]!=a)+
           (s[n-1][n-2]!=b)+
           (s[n-2][n-1]!=b)>2)
            swap(a,b);
        set<pii> inv;
        if(s[0][1]!=a) inv.insert({0,1});
        if(s[1][0]!=a) inv.insert({1,0});
        if(s[n-1][n-2]!=b) inv.insert({n-1,n-2});
        if(s[n-2][n-1]!=b) inv.insert({n-2,n-1});
        cout<<inv.size()<<"\n";
        for(auto [x,y]:inv)
            cout<<x+1<<" "<<y+1<<"\n";
    }
}