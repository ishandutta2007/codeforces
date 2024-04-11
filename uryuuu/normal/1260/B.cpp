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
const int maxn=2005;
int pd(int q,int w)
{
    int x=q-w;
    q-=2*x;
    w-=x;
    if(q==w&&q%3==0)
    {
        int d=q/3;
        if(d+x<0||d<0)
            return 0;
        else
            return 1;
    }
    return 0;
}
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
    int a,b;
    cin>>a>>b;
    if(pd(a,b)||pd(b,a))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    return 0;
        
}