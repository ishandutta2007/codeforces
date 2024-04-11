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
        string x;
        cin>>x;
        int n=x.size();
        int r=count(x.begin(),x.end(),'R');
        int s=count(x.begin(),x.end(),'S');
        int p=count(x.begin(),x.end(),'P');
        if(r>=s&&r>=p)
            cout<<string(n,'P')<<"\n";
        else if(s>=p)
            cout<<string(n,'R')<<"\n";
        else
            cout<<string(n,'S')<<"\n";
    }
}