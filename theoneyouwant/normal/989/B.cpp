/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p,x=0;
    cin>>n>>p;
    string s;
    cin>>s;
    for(int i=0;i<p;i++)
    {
        int a=1;
        while(a*p+i<n)
        {
            if(s[a*p+i]!=s[i] || (s[a*p+i]=='.' && s[i]=='.'))
            {
                x=a*p+i;
                break;
            }
            a++;
        }
    }
    if(x==0)
    {
        cout<<"No";
    }
    else
    {
        if(s[x%p]=='.')
        {
            if(s[x]=='1')
            {
                s[x%p]='0';
            }
            else 
            {
                s[x%p]='1';
            }
        }
        else
        {
            if(s[x%p]=='0')
            {
                s[x]='1';
            }
            else
            {
                s[x]='0';
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                cout<<"0";
            }
            else
            {
                cout<<s[i];
            }
        }
    }
    return 0;
}