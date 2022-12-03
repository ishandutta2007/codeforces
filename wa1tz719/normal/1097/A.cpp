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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a;
    cin>>a;
    int i;
    bool ans=false;
    for (i=0;i<5;i++)
    {
        string b;
        cin>>b;
        if ((a[0]==b[0])||(a[1]==b[1]))
        {
            ans=true;
        }
    }
    if (ans)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}