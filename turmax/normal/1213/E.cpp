#include <bits/stdc++.h>

using namespace std;
#define int long long
string s1;
string s2;
bool check(int a,int b,int c)
{
    if(a==(s1[0]-'a') && b==(s1[1]-'a'))
    {
        return false;
    }
    if(a==(s2[0]-'a') && b==(s2[1]-'a'))
    {
        return false;
    }
    if(b==(s1[0]-'a') && c==(s1[1]-'a'))
    {
        return false;
    }
    if(b==(s2[0]-'a') && c==(s2[1]-'a'))
    {
        return false;
    }
    if(c==(s1[0]-'a') && a==(s1[1]-'a'))
    {
        return false;
    }
    if(c==(s2[0]-'a') && a==(s2[1]-'a'))
    {
        return false;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cin>>s1;
    cin>>s2;
    string s;
    for(int i=0;i<3;++i)
    {
        if(s.size()>0)
        {
            break;
        }
        for(int j=0;j<3;++j)
        {
            if(s.size()>0)
            {
                break;
            }
            for(int k=0;k<3;++k)
            {
                if(s.size()>0)
                {
                    break;
                }
                if(i==j || j==k || k==i)
                {
                    continue;
                }
                else
                {
                    if(check(i,j,k))
                    {
                        s+=('a'+i);
                        s+=('a'+j);
                        s+=('a'+k);
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;
    if(s.size()>0)
    {
    for(int i=0;i<n;++i)
    {
        cout<<s;
    }
    }
    else
    {
        if(s1[1]==s2[1])
        {
        for(int i=0;i<n;++i)
        {
            cout<<s1[1];
        }
        for(int i=0;i<n;++i)
        {
            cout<<s1[0];
        }
        for(int i=0;i<n;++i)
        {
            cout<<s2[0];
        }
        }
        else if(s1[0]==s2[0])
        {
            for(int i=0;i<n;++i)
            {
            cout<<s1[1];
            }
            for(int i=0;i<n;++i)
            {
            cout<<s2[1];
            }
            for(int i=0;i<n;++i)
            {
            cout<<s1[0];
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                cout<<s1[0];
            }
            for(int i=0;i<n;++i)
            {
                cout<<((char) ('a'+(3-(s1[0]-'a')-(s1[1]-'a'))));
            }
            for(int i=0;i<n;++i)
            {
                cout<<s1[1];
            }
        }
    }
    return 0;
}