#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;

vector<int>v;

int main()
{
    int n;
    cin>>n;
    ll ans=(ll)n*(n-1)/2;
    string s;
    cin>>s;
    for(int i=0,cnt=0;i<s.length();i++)
    {
        if(i==0||s[i]==s[i-1])cnt++;
        else
        {
            v.push_back(cnt);
            cnt=1;
        }

        if(i==s.length()-1)v.push_back(cnt);
    }

    ans+=v.size()-1;

    if(v.size()!=1)
    {
        ans-=v[0];
        ans-=v[v.size()-1];
        for(int i=1;i<v.size()-1;i++)
            ans-=v[i]*2;
    }

    cout<<ans<<endl;
    return 0;
}