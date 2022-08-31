//zzqXm
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
pair<string,string> strs[100001];
map<string,int> yuan,xian;
map<int,string> yuann,xiann;
int did=0;
string a,b;
int main()
{
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        if(xian[b]) continue;
        if(!xian[a])
        {
            yuan[a]=++did;
            yuann[did]=a;
            xian[a]=did;
            xiann[did]=a;
        }
        xian[b]=xian[a];
        xiann[xian[a]]=b;
        xian[a]=0;
    }
    for(int i=1;i<=did;i++)
    {
        strs[i].first=yuann[i];
        strs[i].second=xiann[i];
    }
    sort(strs+1,strs+1+did);
    cout<<did<<"\n";
    for(int i=1;i<=did;i++) cout<<strs[i].first<<" "<<strs[i].second<<"\n";
}