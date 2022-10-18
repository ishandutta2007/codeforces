#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

int p[2*N];
bool b[N];

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
        for(int i=1;i<=2*n;i++)
            cin>>p[i];
        vector<int> v;
        int last=0;
        for(int i=1;i<=2*n;i++)
        {
            if(p[i]>last)
                v.push_back(0),
                last=p[i];
            v.back()++;
        }
//        cout<<n<<" : ";
//        for(int x:v)
//            cout<<x<<" ";
//        cout<<" -> ";
        b[0]=true;
        for(int i=1;i<=n;i++)
            b[i]=false;
        for(int x:v)
            for(int i=n;i>=x;i--)
                b[i]|=b[i-x];
        cout<<(b[n]?"YES\n":"NO\n");
    }
}