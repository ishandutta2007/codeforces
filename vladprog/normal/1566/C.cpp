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
        string a,b;
        cin>>a>>b;
        string c(n,'-');
        for(int i=0;i<n;i++)
            if(a[i]!=b[i])
                c[i]='2';
            else
                c[i]=a[i];
        int ans=0;
        for(int i=0;i<n;i++)
            if(c[i]=='2')
                ans+=2;
            else if(i+1<n&&
                    c[i+1]!='2'&&
                    c[i]!=c[i+1])
                ans+=2,
                i++;
            else if(c[i]=='0')
                ans++;
        cout<<ans<<"\n";
    }
}