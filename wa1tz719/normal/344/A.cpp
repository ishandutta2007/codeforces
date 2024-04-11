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
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a,b;
    a="";
    int n;
    cin>>n;
    int i;
    int sum=0;
    for (i=0;i<n;i++)
    {
        cin>>b;
        if (b!=a) sum++;
        a=b;
    }
    cout<<sum<<endl;
    return 0;
}