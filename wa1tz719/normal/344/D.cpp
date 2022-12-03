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
char b[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a;
    cin>>a;
    int i,now=0;
    for (i=0;i<a.length();i++)
    {
        if (now==0) b[now++]=a[i];
        else if (b[now-1]!=a[i]) b[now++]=a[i];
        else now--;
    }
    if (now>0) cout<<"No"; else cout<<"Yes";
    return 0;
}