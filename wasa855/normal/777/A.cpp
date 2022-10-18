#include<bits/stdc++.h>
using namespace std;
int a[7][4]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1},{0,1,2}};
int main()
{
    int n,m;
    cin>>n>>m;
    n%=6;
    cout<<a[n][m]<<endl;
    return 0;
}
//adxiusRFestsaexTAwES