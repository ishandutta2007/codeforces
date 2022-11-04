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
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[100010];
int pd(int n)
{
    if(n>999)
        return 0;
    int a=n%10;
    int b=n/100;
    int c=(n%100)/10;
    if((a+b+c)%4==0)
        return 1;
    return 0;
}
int main()
{
    int q;
    cin>>q;
    if(q>996)
    {
        cout<<1003<<endl;
        return 0;
    }
    for(int i=0;i<100;i++)
    {
        if(pd(q+i))
        {
            cout<<q+i<<endl;
            return 0;
        }
    }
    return 0;
}