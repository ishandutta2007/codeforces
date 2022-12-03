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
string a[55],b[55];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int q;
    cin>>q;
    for (i=0;i<q;i++)
    {
        int x;
        cin>>x;
        cout<<a[(x-1)%n]<<b[(x-1)%m]<<"\n";
    }
    return 0;
}