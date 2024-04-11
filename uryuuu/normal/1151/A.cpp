#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#define ll long long
#define N 500005
#define M 25
#define mod 1000000007
int inf=0x3f3f3f3f;
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    string b="ACTG";
    int zx=1000;
    for(int i=0;i+3<n;i++)
    {
        int z=0;
        for(int j=0;j<4;j++)
        {
            z+=min(26-abs(b[j]-a[i+j]),abs(b[j]-a[i+j]));
        }
        zx=min(zx,z);
    }
    cout<<zx<<endl;
    return 0;
}