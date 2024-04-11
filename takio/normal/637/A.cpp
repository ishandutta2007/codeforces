#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1005;
map<int,int>mp;
int main()
{
    int n;
    scanf("%d",&n);
    int res=0,num=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(++mp[a]>num)
        {
            res=a;
            num=mp[a];
        }
    }
    printf("%d\n",res);
    return 0;
}