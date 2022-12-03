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
char a[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    scanf("%s",a);
    int i;
    char last_char='\0';
    int zeros=0;
    for (i=0;i<n;i++)
    {
        if (a[i]==last_char)
        {
            continue;
        }
        last_char=a[i];
        if (a[i]=='0')
        {
            zeros++;
        }
    }
    if (zeros==0)
    {
        puts("0");
        return 0;
    }
    cout<<min(zeros*(long long)y,y+(long long)(zeros-1)*x)<<endl;
    return 0;
}