#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int y[9]={0,3,6,1,4,7,2,5,8};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s[9];
        for(int i=0;i<9;i++)
            cin>>s[i];
        for(int x=0;x<9;x++)
            s[x][y[x]]=(s[x][y[x]]-'1'+1)%9+'1';
        for(int i=0;i<9;i++)
            cout<<s[i]<<"\n";
    }
}