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
    string x;
    cin>>x;
    int i;
    for (i=1;i<x.length();i++)
    {
        if (x[i]!=x[i-1]) break;
    }
    if (i==x.length())
    {
        puts("0");
        return 0;
    }
    for (i=0;i<x.length();i++)
    {
        if (x[i]!=x[x.length()-1-i]) break;
    }
    if (i==x.length())
    {
        cout<<x.length()-1<<endl;
    }
    else
    {
        cout<<x.length()<<endl;
    }
    return 0;
}