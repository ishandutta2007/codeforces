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
        string s;
        cin>>s;
        bool eq=true;
        for(char c:s)
            if(c!=s[0])
                eq=false;
        if(eq)
            cout<<s;
        else
            for(int i=0;i<s.size();i++)
                cout<<"01";
        cout<<"\n";
    }
}