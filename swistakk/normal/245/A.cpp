#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define uint long long int
using namespace std;
int w[5][5];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int r;
    int a;
    int l1=0, p1=0, l2=0, p2=0;
    for(int i=1; i<=n; i++)
    {
        cin>>r;
        for(int j=1; j<=2; j++)
        {
            cin>>a;
            w[r][j]+=a;
        }
    }
    if(w[1][1]>=w[1][2])
    {
        cout<<"LIVE"<<endl;
    }
    else
    {
        cout<<"DEAD"<<endl;
    }
    if(w[2][1]>=w[2][2])
    {
        cout<<"LIVE"<<endl;
    }
    else
    {
        cout<<"DEAD"<<endl;
    }
    
    
    
    
    // system("pause");
    return 0;
}