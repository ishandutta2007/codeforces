#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long n,t[1000001];
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",t+i);
    sort(t+1,t+1+n);
    long long qzh=0,sb=0;
    for(int i=1;i<=n;i++)
    {
        if(qzh<=t[i]) 
        {
            ++sb;
            qzh+=t[i];
        } 
    }
    cout<<sb;
}