#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,data[1000001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp; cin>>tmp;
        data[i]=tmp+i-1;
    }
    sort(data+1,data+1+n);
    bool ok=1;
    for(int i=2;i<=n;i++)
    {
        data[i]-=i-1;
        if(data[i]<data[i-1]) {ok=0; break;}
    }
    if(!ok) cout<<":(";
    else
    {
        for(int i=1;i<=n;i++) cout<<data[i]<<" ";
    }
}