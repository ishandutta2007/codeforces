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
        set<char> ok;
        char p=0;
        int k=0;
        for(char c:s)
            if(c==p)
                k++;
            else
            {
                if(k%2)
                    ok.insert(p);
                p=c,k=1;
            }
        if(k%2)
            ok.insert(p);
        for(char c:ok)
            cout<<c;
        cout<<"\n";
    }
}