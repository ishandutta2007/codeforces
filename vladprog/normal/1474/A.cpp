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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a;
        cin>>a;
        string b(n,'_');
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]-'0'+1==last)
                b[i]='0';
            else
                b[i]='1';
            last=(a[i]-'0')+(b[i]-'0');
        }
        cout<<b<<"\n";
    }
}