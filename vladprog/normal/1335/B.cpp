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
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        for(int i=0;i<b;i++)
            s+='a'+i;
        while(s.size()<a)
            s+=s.back();
        while(s.size()<n)
            s+=s;
        s=s.substr(0,n);
        cout<<s<<"\n";
    }
}