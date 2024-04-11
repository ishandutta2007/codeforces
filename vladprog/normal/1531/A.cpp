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

    int n;
    cin>>n;
    bool can=true;
    string color="blue";
    while(n--)
    {
        string cur;
        cin>>cur;
        if(cur=="lock")
            can=false;
        else if(cur=="unlock")
            can=true;
        else if(can)
            color=cur;
    }
    cout<<color;
}