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
int gcd(int x,int y)
{
    if (x%y==0) return y;
    else return gcd(y,x%y);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int gcds;
    scanf("%d",&gcds);
    for (i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        gcds=gcd(gcds,x);
    }
    printf("%d\n",gcds*n);
    return 0;
}