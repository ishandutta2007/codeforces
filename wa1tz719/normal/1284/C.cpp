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
int fact[250005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,modo;
    scanf("%d%d",&n,&modo);
    fact[0]=1;
    int i;
    for (i=1;i<=n;i++)
    {
        fact[i]=(long long)fact[i-1]*i%modo;
    }
    int ans=0;
    for (i=1;i<=n;i++)
    {
        ans=(ans+(long long)fact[i]*fact[n-i]%modo*(n-i+1)%modo*(n-i+1)%modo)%modo;
    }
    printf("%d\n",ans);
    return 0;
}