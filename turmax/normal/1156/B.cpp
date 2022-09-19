#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
string res;
set <char> b;
void cou(char x)
{
    if(b.count(x)==0)
    {
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==x)
        {
            res+=x;
        }
    }
    b.insert(x);
    }
}
char order(set <char> a,int x)
{
    set <char>::iterator iter;
    iter=a.begin();
    for(int i=0;i<x;++i)
    {
        iter++;
    }
    return (*iter);
}
int32_t main()
{
    int n;
    cin>>n;
    set <char> a;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        res.clear();
        b.clear();
        a.clear();
        for(int i=0;i<s.size();++i)
        {
            a.insert(s[i]);
        }
        if(a.size()==1)
        {
            cout<<s<<endl;
            continue;
        }
        else if(a.size()==2)
        {
            if((order(a,1)-order(a,0))==1)
            {
                cout<<"No answer"<<endl;
                continue;
            }
            else
            {
                cou(order(a,0));
                cou(order(a,1));
                cout<<res<<endl;
                continue;
            }
        }
        else if(a.size()==3)
        {
            if((order(a,2)-order(a,1))==1 && ((order(a,1)-order(a,0))==1))
            {
                cout<<"No answer"<<endl;
                continue;
            }
            else if((order(a,2)-order(a,1))!=1)
            {
                cou(order(a,0));
                cou(order(a,2));
                cou(order(a,1));
                cout<<res<<endl;
                continue;
            }
            else if((order(a,1)-order(a,0))!=1)
            {
                cou(order(a,2));
                cou(order(a,0));
                cou(order(a,1));
                cout<<res<<endl;
                continue;
            }
        }
        else if(a.size()==4)
        {
            cou(order(a,2));
            cou(order(a,0));
            cou(order(a,3));
            cou(order(a,1));
            cout<<res<<endl;
            continue;
        }
        else
        {
            for(int i=0;i<a.size();i+=2)
            {
                cou(order(a,i));
            }
            for(int i=1;i<a.size();i+=2)
            {
                cou(order(a,i));
            }
            cout<<res<<endl;
            continue;
        }
    }
    return 0;
}