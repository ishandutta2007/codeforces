/*
By: zzq
P2
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <stack>
using namespace std;
int n,k,a[10001],mn=0x7ffffff;
vector<int> sb[10001];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    for(int i=1;i<=n;i++) a[i]-=mn;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j])
            {
                a[j]--; sb[j].push_back(i);
            }
        }
    }
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0) ok=0;
    }
    if(!ok) {cout<<"NO"; return 0;}
    else
    {
    cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sb[i].size();j++) cout<<sb[i][j]<<" ";
        for(int i=1;i<=mn;i++) cout<<1<<" ";
        cout<<"\n";
        }
    }
    return 0;
}