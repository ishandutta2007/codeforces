#include <bits/stdc++.h>

using namespace std;

int t,n;
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n>>s;
        if(n<11)
        {
            cout<<"NO\n";
            continue;
        }
        bool ok=0;
        for (int i=0;i<=n-11;++i)
        {
            if (s[i]=='8') ok=1;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
}