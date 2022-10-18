#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string p,h;
        cin>>p>>h;
        int n=p.size(),k=h.size();
        sort(p.begin(),p.end());
        bool yes=false;
        for(int l=0;l+n-1<k;l++)
        {
            string q=h.substr(l,n);
            sort(q.begin(),q.end());
            if(p==q)
                yes=true;
        }
        cout<<(yes?"YES\n":"NO\n");
    }
}