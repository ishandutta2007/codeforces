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
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a,b;
    scanf("%d%d",&a,&b);
    int i;
    int sum=0;
    for (i=1;i<b;i++)
    {
        sum=(sum+(long long)i*a)%modo;
        sum=(sum+((long long)a*(a+1)/2)%modo*i%modo*b)%modo;
    }
    printf("%d\n",sum);
    return 0;
}