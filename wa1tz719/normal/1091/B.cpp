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
    int n;
    cin>>n;
    int i;
    int x,y;
    long long sumx=0,sumy=0;
    for (i=0;i<2*n;i++)
    {
        cin>>x>>y;
        sumx+=x;
        sumy+=y;
    }
    cout<<sumx/n<<" "<<sumy/n<<endl;
    return 0;
}