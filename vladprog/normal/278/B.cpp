#include<bits/stdc++.h>

using namespace std;

void next(string &s)
{
    bool z=true;
    for(int i=0;i<s.size();i++)
        if(s[i]!='z')
            z=false;
    if(z)
    {
        s.resize(s.size()+1);
        for(int i=0;i<s.size();i++)
            s[i]='a';
    }
    else
    {
        for(int i=s.size()-1;i>=0;i--)
            if(s[i]=='z')
                s[i]='a';
            else
            {
                s[i]++;
                break;
            }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    string s[n];
    for(int i=0;i<n;i++)
    {
        char c[21];
        scanf("%s",c);
        s[i]=c;
    }
    string t;
    bool ok;
    do
    {
        next(t);
        //printf("%s\n",t.c_str());
        ok=true;
        for(int i=0;i<n;i++)
            ok=ok&&(s[i].find(t)==string::npos);
    }
    while(!ok);
    printf("%s",t.c_str());
}