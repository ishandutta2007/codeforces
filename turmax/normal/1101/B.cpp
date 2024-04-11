#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
int main()
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int x=s.size();
    char c1="["[0];
    char c2="]"[0];
    char c3=":"[0];
    char c4="|"[0];
    int v=s.size();
    int g1,g2;
    int sum=0;
    int y=0;
    for(int i=0;i<v;++i)
    {
        if(s[i]==c1)
        {
            g1=i;
            sum+=g1;
            y=1;
            break;
        }
    }
    if(y==0)
    {
        cout<<(-1);
        return 0;
    }
    y=0;
    for(int i=0;i<v;++i)
    {
        if(s[i]==c2)
        {
            g2=i;
            y=1;
        }
    }
    if(y==0)
    {
        cout<<(-1);
        return 0;
    }
    int l1,l2;
    y=0;
    for(int i=(g1+1);i<g2;++i)
    {
        if(s[i]==c3)
        {
            l1=i;
            y=1;
            break;
        }
    }
    if(y==0)
    {
        cout<<(-1);
        return 0;
    }
    y=0;
    for(int i=(l1+1);i<g2;++i)
    {
        if(s[i]==s[l1])
        {
            l2=i;
            y=1;
        }
    }
    if(y==0)
    {
        cout<<(-1);
        return 0;
    }
    sum=l1+(v-l2-1)-2;
    for(int i=(l1+1);i<(l2);++i)
    {
        if(s[i]!=c4)
        {
            ++sum;
        }
    }
    cout<<(x-sum);
    return 0;
}