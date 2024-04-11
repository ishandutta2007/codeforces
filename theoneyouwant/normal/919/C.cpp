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
    int n,m,k;
    cin>>n>>m>>k;
    long long int total=0;
    bool matrix[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char a;
            cin>>a;
            if(a=='*')
            {
                matrix[i][j]=0;
            }
            else
            {
                matrix[i][j]=1;
            }
        }
    }
    vector<int> v;
    int length=0;
    if(k!=1)
    {
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==1)
            {
                length++;
            }
            else
            {
                if(length>=k)
                {
                    v.push_back(length);
                }
                length=0;
            }
        }
        if(length>=k)
        {
            v.push_back(length);
        }
        length=0;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[j][i]==1)
            {
                length++;
            }
            else
            {
                if(length>=k)
                {
                    v.push_back(length);
                }
                length=0;
            }
        }
        if(length>=k)
        {
            v.push_back(length);
        }
        length=0;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        total+=((*it)-k+1);
    }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    total++;
                }
            }
        }
    }
    cout<<total;
    return 0;
}