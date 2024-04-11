#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll pre=-1, bck;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=s[0]) {pre=i-1;break;}
    }
    if(pre==-1)
    {
        cout<<n*(n+1)/2%mod<<endl;
    }
    else
    {
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]!=s[s.size()-1]) {bck=i+1;break;}
        }
        ll a = pre+1, b=s.size()-bck, c=s.size()-a-b;
        if(s[0]==s[s.size()-1])
        {
            cout<<(a+1)*(b+1)%mod<<endl;
        }
        else
        {
            cout<<a+b+1<<endl;
        }
    }
}