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
#define reverse sikd012l
char a[100005];
int reverse[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%s",a);
    int i;
    for (i=0;a[i]!='\0';i++)
    {
        if (a[i]=='a')
        {
            reverse[i]^=1;
            if (i!=0)
            {
                reverse[i-1]^=1;
            }
        }
    }
    for (i=0;a[i]!='\0';i++)
    {
        printf("%d ",reverse[i]);
    }
    return 0;
}