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
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int modo=998244353;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    int sum=1;
    for (i=1;i<=n;i++)
    {
        sum=((long long)sum*i)%modo;
    }
    int ans=((long long)sum*n)%modo;
    sum=1;
    for (i=n;i>=2;i--)
    {
        sum=((long long)sum*i)%modo;
        ans-=sum;
        ans=(ans+modo)%modo;
    }
    printf("%d\n",ans);
    return 0;
}