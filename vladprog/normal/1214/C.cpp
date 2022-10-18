#pragma GCC optimize("O3")
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

    int n;
    string s;
    cin>>n>>s;
    int d=0;
    int cl=0;
    for(char c:s)
        if(c=='(')
           d++;
        else if(d==0)
            cl++;
        else
            d--;
    if(cl>1)
        cout<<"No",exit(0);
    if(cl==1)
        d--;
    if(d)
        cout<<"No";
    else
        cout<<"Yes";
}