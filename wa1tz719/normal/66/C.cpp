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
map<string,int> ma[5][2];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a;
    int max1=0,max2=0;
    for (;cin>>a;)
    {
        int x=a[0]-'C';
        int i;
        int tag=0;
        int cnt=0;
        for (i=a.length();i>=3;i--)
        {
            if (a[i]=='\\')
            {
                ma[x][0][a.substr(0,i)]+=cnt;
                cnt-=(ma[x][1][a.substr(0,i)]!=0);
                tag=1;
                ma[x][1][a.substr(0,i)]++;
                max1=max(max1,ma[x][0][a.substr(0,i)]);
                max2=max(max2,ma[x][1][a.substr(0,i)]);
                //cout<<a.substr(0,i)<<endl;
                cnt++;
            }
        }
    }
    printf("%d %d\n",max1,max2);
    return 0;
}