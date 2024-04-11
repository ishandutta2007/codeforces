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
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int a[2],b[2];
int main()
{
    int aa;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>aa;
        a[aa%2]++;
    }
    for(int i=0;i<m;i++)
    {
        cin>>aa;
        b[aa%2]++;
    }
    cout<<min(b[0],a[1])+min(b[1],a[0])<<endl;
    return 0;
}