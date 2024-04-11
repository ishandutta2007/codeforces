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
    int a,b,c;
    cin>>a>>b>>c;
    int i;
    for (i=0;i<=a;i++)
    {
        int j=a-i;
        int k=b-j;
        if (i==c-k)
        {
            if (((int)(i==0)+(int)(j==0)+(int)(k==0)<2)&&(i>=0)&&(j>=0)&&(k>=0))
            {
                cout<<j<<" "<<k<<" "<<i<<endl;
                return 0;
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}