#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    pair<ll,bool>a[10]={};
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        a[s[0]-'a'].second=true;
        reverse(s.begin(),s.end());
        for(ll j=0,p=1;j<s.size();j++,p*=10)
            a[s[j]-'a'].first+=p;
    }
    sort(a,a+10,greater< pair<ll,bool> >());
    bool is0=false;
    ll s=0;
    for(ll i=0;i<10;i++)
        if(!is0)
            if(!a[i].second)
                is0=true;
            else
                s+=a[i].first*(i+1);
        else
            s+=a[i].first*i;
    cout<<s;
}