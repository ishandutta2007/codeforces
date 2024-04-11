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
char a[105][105];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (a[i][j]=='#')
            {
                if ((j==0)||(j==n-1))
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                if (i>=n-2)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                if ((a[i+1][j]!='#')||(a[i+1][j+1]!='#')||(a[i+1][j-1]!='#')||(a[i+2][j]!='#'))
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                a[i][j]='.';
                a[i+1][j]='.';
                a[i+1][j+1]='.';
                a[i+1][j-1]='.';
                a[i+2][j]='.';
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}