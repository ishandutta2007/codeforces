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
int a[105];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    int ma=0;
    int cnt=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
        cnt+=a[i];
    }
    int p=cnt*2+1;
    int ans=p/n;
    if (p%n!=0)
    {
        ans++;
    }
    printf("%d\n",max(ans,ma));
    return 0;
}