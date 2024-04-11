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
char op[15];
char oper[500005];
int num[500005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%s",op);
        oper[i]=op[0];
        scanf("%d",&num[i]);
    }
    int aand=1023,oor=0,xxor=0;
    for (i=0;i<10;i++)
    {
        int j;
        bool n0=false,n1=true;
        for (j=0;j<n;j++)
        {
            bool now;
            if ((1<<i)&num[j]) now=true; else now=false;
            if (oper[j]=='^')
            {
                n0^=now;
                n1^=now;
            }
            if (oper[j]=='|')
            {
                n0|=now;
                n1|=now;
            }
            if (oper[j]=='&')
            {
                n0&=now;
                n1&=now;
            }
        }
        if (n0)
        {
            if (n1)
            {
                oor^=(1<<i);
            }
            else
            {
                xxor^=(1<<i);
            }
        }
        else
        {
            if (!n1)
            {
                aand^=(1<<i);
            }
        }
    }
    printf("3\n");
    printf("& %d\n",aand);
    printf("^ %d\n",xxor);
    printf("| %d\n",oor);
    return 0;
}