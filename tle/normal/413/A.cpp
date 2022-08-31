//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,m,minn,maxn;
int main()
{
    cin>>n>>m;
    if(n<m)
    {
        cout<<"Incorrect";
        return 0;
    }
    cin>>minn>>maxn;
    bool minm=0,maxm=0;
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        if(t<=maxn&&t>=minn);else
        {
            cout<<"Incorrect";
            return 0;
        }
        if(t==maxn) maxm=1; 
        if(t==minn) minm=1;
    }
    if(n==m&&(!maxm||!minm)) cout<<"Incorrect"; else
    if(n==m+1&&!maxm&&!minm) cout<<"Incorrect"; else
    cout<<"Correct";
    return 0;
}