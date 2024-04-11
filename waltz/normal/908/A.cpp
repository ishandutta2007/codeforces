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
char a[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%s",a);
    int i;
    int ans=0;
    for (i=0;a[i]!='\0';i++)
    {
        if ((a[i]=='1')||(a[i]=='3')||(a[i]=='5')||(a[i]=='7')||(a[i]=='9')||(a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}