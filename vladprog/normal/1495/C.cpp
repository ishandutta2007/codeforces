#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

string s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n;i+=3)
            s[i]=string(m,'X');
        for(int i=2;i<n;i+=3)
            if(m==1||
               s[i-1][1]=='.'&&s[i][1]=='.')
                s[i-1][0]=s[i][0]='X';
            else
                s[i-1][1]=s[i][1]='X';
        if(n%3==0)
            for(int j=0;j<m;j++)
                if(s[n-1][j]=='X')
                    s[n-2][j]='X';
//        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<s[i]<<"\n";
//        cout<<endl;
    }
}