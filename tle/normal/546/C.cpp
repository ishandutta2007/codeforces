#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
int n,k1,k2,kt;
queue<int> ac,bc;
int main()
{
    cin>>n>>k1;
    for(int i=1;i<=k1;i++)
    {
        cin>>kt;
        ac.push(kt);
    }
    cin>>k2;
    for(int i=1;i<=k2;i++)
    {
        cin>>kt;
        bc.push(kt);
    }
    int tt=0;
    while(tt<=300000&&!ac.empty()&&!bc.empty())
    {
        int ta=ac.front(),tb=bc.front();
        ac.pop(); bc.pop();
        if(ta>tb)
        {
            ac.push(tb); ac.push(ta);
        }
        else
        {
            bc.push(ta); bc.push(tb);
        }
        ++tt;
    }
    if(ac.empty()) cout<<tt<<" 2";
    else if(bc.empty()) cout<<tt<<" 1";
    else cout<<"-1";
}