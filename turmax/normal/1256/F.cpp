#include <bits/stdc++.h>

using namespace std;
#define int long long
int b1[26];
int b2[26];
int curr1;
int curr2;
void ins1(char s)
{
    int x=s-'a';
    int sum=0;
    for(int i=0;i<x;++i)
    {
        sum+=b1[i];
    }
    curr1+=sum;
    curr1%=2;
    b1[x]++;
}
void ins2(char s)
{
    int x=s-'a';
    int sum=0;
    for(int i=0;i<x;++i)
    {
        sum+=b2[i];
    }
    curr2+=sum;
    curr2%=2;
    b2[x]++;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    map <char,int> a1;
    map <char,int> a2;
    bool h;
    while(q>0)
    {
    q--;
    h=true;
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    curr1=0;
    curr2=0;
    for(int i=0;i<26;++i)
    {
        a1['a'+i]=0;
        a2['a'+i]=0;
        b1[i]=0;
        b2[i]=0;
    }
    for(int i=0;i<n;++i)
    {
        a1[s1[i]]++;
        a2[s2[i]]++;
    }
    for(int i=0;i<26;++i)
    {
        if(a1['a'+i]!=a2['a'+i])
        {
            cout<<"NO"<<endl;
            h=false;
            break;
        }
    }
    if(!h)
    {
        continue;
    }
    for(int i=0;i<26;++i)
    {
        if(a1['a'+i]>=2)
        {
            cout<<"YES"<<endl;
            h=false;
            break;
        }
    }
    if(!h)
    {
        continue;
    }
    for(int i=0;i<n;++i)
    {
        ins1(s1[i]);
    }
    for(int i=0;i<n;++i)
    {
        ins2(s2[i]);
    }
    if((curr1%2)==(curr2%2))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}