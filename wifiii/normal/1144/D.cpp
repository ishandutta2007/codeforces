#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[200005],b[200005];
int main()
{
    int n;
    cin>>n;
    ii
    {
        cin>>a[i];
        b[a[i]]++;
    }
    int m=-1,mv=0;
    ii if(b[a[i]]>m) m=b[a[i]],mv=a[i];
    int ans=n-m;
    cout<<ans<<endl;
    ii
    {
        if(a[i] != mv) continue;
        int p = i-1;
        while(p>=1 && a[p] != mv)
        {
            if(a[p] > mv)
            {
                cout << 2 << " " << p << " " << p+1 << endl;
            }
            else
            {
                cout << 1 << " " << p << " " << p+1 << endl;
            }
            a[p] = mv;
            p--;
        }
        p = i+1;
        while(p<=n && a[p] != mv)
        {
            if(a[p] > mv)
            {
                cout << 2 << " " << p << " " << p-1 << endl;
            }
            else
            {
                cout << 1 << " " << p << " " << p-1 << endl;
            }
            a[p] = mv;
            p++;
        }
    }
}