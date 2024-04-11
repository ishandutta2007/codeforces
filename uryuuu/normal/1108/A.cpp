//#include <bits/stdc++.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1000005;

int father[30010];
int size[30010];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

//struct node
//{
//    int l,r
//}a[10];
int main()
{
    sync;
    int n;
    cin>>n;
    int a,b,c,d;
    int e,f;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        e=a;
        f=d;
        if(f==e)
        {
            f=c;
        }
        cout<<a<<' '<<f<<endl;
    }
    return 0;
}