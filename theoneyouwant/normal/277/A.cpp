/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    int done=0;
    cin>>n>>m;
    int ok[n+1]={0};
    int max=0;
    int z1=0;
    vector<int> v[n+1];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a>max)
        {
            z1=i;
            max =a;
        }
        for(int j=0;j<a;j++)
        {
            int b;
            cin>>b;
            v[i].push_back(b);
        }
    }
    bool lang[m+1]={0};
    for(vector<int>::iterator it = v[z1].begin();it!=v[z1].end();it++)
    {
        lang[(*it)]=1;
    }
    for(int i=1;i<=n;i++)
    {
        bool c=0;
        for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            if(lang[(*it)]==1)
            {
                c=1;
                break;
            }
        }
        if(c==1)
     
     {
         for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            lang[(*it)]=1;
        }
    }
    }
    long long int counter=0;
    while(done!=n)
    {
        bool b=0;
        for(int i=1;i<=n;i++)
    {
        bool c=0;
        for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            if(lang[(*it)]==1)
            {
                c=1;
                break;
            }
        }
        if(c==1 && ok[i]==0)
      {  ok[i]=1;
        done++;
        for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            lang[(*it)]=1;
        }
     }
     else if(b==0 && ok[i]==0)
     {
         ok[i]=1;
         done++;
         b=1;
         counter++;
         for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            lang[(*it)]=1;
        }
        if(v[i].size()==0)
        {
            bool zx=0;
            for(int j=1;j<=m;j++)
            {
                if(lang[j]!=0)
                {
                    zx=1;
                    v[i].push_back(j);
                break;
                }
            }
            if(zx==0)
            {
                v[i].push_back(1);
                lang[1]=1;
            }
        }
     }
    }
    }
    cout<<counter;
    return 0;
}