#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
int n,m,a[10001],gg[10001];
queue<int> rp;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        rp.push(i);
    }
    int last=0;
    while(!rp.empty())
    {
        last=rp.front(); rp.pop();
        gg[last]+=m;
        if(gg[last]<a[last]) rp.push(last);
    }
    cout<<last<<"\n";
}