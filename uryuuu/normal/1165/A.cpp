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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
char a[200010];
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    cin>>a;
    reverse(a,a+n);
    int b=0;
    if(a[y]=='0')
        b=1;
    else
        b=-1;
    int c=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]=='1')
            c++;
    }
    cout<<c+b<<endl;
    return 0;
}