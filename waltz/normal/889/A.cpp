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
bool vis[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int sum=1;
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (vis[x]) sum++;
        vis[x]=true;
    }
    printf("%d\n",sum);
    return 0;
}