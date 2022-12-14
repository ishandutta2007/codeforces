#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e5;
const int maxn=2e5+10;

int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    if(n==1&&k==1)
    {
        cout<<0;
        return 0;
    }

    if(k&&s[0]!='1')
    {
        s[0]='1';
        k--;
    }
    for(int i=1;i<n;i++)
    {
        if(!k)break;
        if(s[i]!='0')
        {
            s[i]='0';
            k--;
        }
    }
    cout<<s;
    return 0;
}