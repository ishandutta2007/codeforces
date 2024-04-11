#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int l[N],r[N];

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
        string s;
        cin>>n>>s;
        s="_"+s+"_";
        l[0]=r[0]=l[n+1]=r[n+1]=0;
        l[1]=1;
        for(int i=2;i<=n;i++)
            l[i]=(s[i]==s[i-1]?1:l[i-1]+1);
        r[n]=1;
        for(int i=n-1;i>=1;i--)
            r[i]=(s[i]==s[i+1]?1:r[i+1]+1);
        for(int i=0;i<=n;i++)
            cout<<(s[i]=='L'?l[i]:0)+
                  (s[i+1]=='R'?r[i+1]:0)+1<<" ";
        cout<<"\n";
    }
}