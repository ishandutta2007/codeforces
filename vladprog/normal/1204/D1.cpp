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

    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    string t;
    int k=0;
    for(char c:s)
        if(c=='0')
            t+='0',
            k++;
        else if(k)
            t+='1',
            k--;
        else
            t+='0';
    reverse(t.begin(),t.end());
    cout<<t;
}