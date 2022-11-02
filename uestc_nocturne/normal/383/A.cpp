/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=200100;
int x,n;
int main()
{
    while(~scanf("%d",&n))
    {
        LL ret=0;
        int r=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==1)r++;
            else ret+=r;
        }
        cout<<ret<<endl;
    }
}