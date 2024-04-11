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

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        bool two=false;
        for(int i=0;i+1<s.size();i++)
            if((s[i]-'0')+(s[i+1]-'0')>=10)
                two=true;
        if(two)
        {
            for(int i=s.size()-2;i>=0;i--)
                if((s[i]-'0')+(s[i+1]-'0')>=10)
                {
                    cout<<s.substr(0,i)<<(s[i]-'0')+(s[i+1]-'0')<<s.substr(i+2)<<"\n";
                    break;
                }
        }
        else
            cout<<(s[0]-'0')+(s[1]-'0')<<s.substr(2)<<"\n";
    }
}