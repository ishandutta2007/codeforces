#include<bits/stdc++.h>

using namespace std;

string s,m="";

bool pal(string t)
{
    string t2=t;
    reverse(t2.begin(),t2.end());
    return t==t2;
}

void p(string t,int k)
{
    if(k==s.length())
    {
        if(pal(t))
            m=max(m,t);
    }
    else
    {
        p(t+s[k],k+1);
        p(t,k+1);
    }
}

int main()
{
    cin>>s;
    p("",0);
    cout<<m;
}