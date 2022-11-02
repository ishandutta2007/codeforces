#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int ok[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    string a;
    cin>>n>>a;
    int i,j;
    for (i=0;i<n;i++)
    {
        ok[i]=true;
    }
    for (i=0;i<n;i++)
    {
        if (a[i]=='L')
        {
            int j;
            for (j=i;j>=0;j--)
            {
                if (a[j]=='R') break;
            }
            if (j<0)
            {
                for (j=i;j>=0;j--)
                {
                    ok[j]=false;
                }
            }
        }
        else if (a[i]=='R')
        {
            int j;
            for (j=i;j<n;j++)
            {
                if (a[j]=='L') break;
            }
            if (j>=n)
            {
                for (j=i;j<n;j++)
                {
                    ok[j]=false;
                }
            }
            else
            {
                int k;
                for (k=i;k<=j;k++)
                {
                    if (!((k==(i+j)/2)&&((i+j)%2==0))) ok[k]=false;
                }
            }
        }
    }
    int sum=0;
    for (i=0;i<n;i++)
    {
        sum+=ok[i];
    }
    cout<<sum<<endl;
    return 0;
}