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
map<int,int> ans;
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
        int x,y;
        scanf("%d%d",&x,&y);
        ans[x]=max(ans[x],y);
    }
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans[x]=max(ans[x],y);
    }
    map<int,int>::iterator ii;
    long long sum=0;
    for (ii=ans.begin();ii!=ans.end();ii++)
    {
        sum+=(*ii).second;
    }
    cout<<sum<<endl;
    return 0;
}