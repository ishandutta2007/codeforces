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
    long long int n,m;
    cin>>n>>m;
    int b;
    int a[n];
    set<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b;
        s.insert(b);
    }
    for(int i=0;i<n;i++)
    {
        if(s.count(a[i])==1)
        {
            cout<<a[i]<<" ";
        }
    }
     return 0;
}