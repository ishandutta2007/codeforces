#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a;
    ios::sync_with_stdio(false);
    cin>>a;
    int k;
    cin>>k;
    int i;
    int te=a.length();
    int sum=0;
    int p=1;
    for (i=0;i<te;i++)
    {
        if ((a[i]=='0')||(a[i]=='5')) sum=(sum+p)%modo;
        p=(p*2)%modo;
    }
    int total=sum;
    int mul=1;
    int count=0;
    for (i=1;i<=100;i++)
    {
        count=(count+mul)%modo;
        mul=(long long)mul*p%modo;
    }
    sum=0;
    for (i=0;i<k-100;i+=100)
    {
        sum=(sum+(long long)total*count)%modo;
        total=(long long)total*mul%modo;
    }
    for (;i<k;i++)
    {
        sum=(sum+total)%modo;
        total=(long long)total*p%modo;
    }
    printf("%d\n",sum);
    return 0;
}