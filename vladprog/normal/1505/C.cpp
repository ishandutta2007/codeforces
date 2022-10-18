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

    string s;
    cin>>s;
    for(int i=2;i<s.size();i++)
        if(s[i]-'A'!=(s[i-1]-'A'+s[i-2]-'A')%26)
            cout<<"NO",exit(0);
    cout<<"YES";
}