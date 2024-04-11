#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[10]={},s=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a[t]++;
        s+=t;
    }
    if(!a[0])
        cout<<-1,exit(0);
    int p=s%3;
    if(p)
    {
        bool ok=false;
        for(int i=0;i<10;i++)
            if(i%3==p&&a[i])
            {
                s-=i;
                a[i]--;
                ok=true;
                break;
            }
        if(!ok)
        {
            for(int i=0;i<10;i++)
                if(i%3==3-p&&a[i])
                {
                    s-=i;
                    a[i]--;
                    break;
                }
            for(int i=0;i<10;i++)
                if(i%3==3-p&&a[i])
                {
                    s-=i;
                    a[i]--;
                    break;
                }
        }
    }
    if(s==0)
        cout<<0;
    else
        for(int i=9;i>=0;i--)
            cout<<string(a[i],char('0'+i));
}