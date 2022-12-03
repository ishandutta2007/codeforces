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
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[1000005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=2;k!=1;i++)
    {
        int p=1;
        for (;k%i==0;)
        {
            k/=i;
            p*=i;
        }
        if (p==1) continue;
        int j;
        for (j=0;j<n;j++)
        {
            if (a[j]%p==0) break;
        }
        if (j==n)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}