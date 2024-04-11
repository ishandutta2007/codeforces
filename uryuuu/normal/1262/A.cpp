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
const int maxn=100005;
struct node
{
    int l,r;
}a[maxn];
bool cmp(node a,node b)
{
    return a.l>b.l;
}
int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].l>>a[i].r;
        }
        sort(a,a+n,cmp);
        int li=a[0].l,ri=a[0].l;
//        cout<<li<<ri<<endl;
        for(int i=1;i<n;i++)
        {
            if(a[i].r<li)
                li=a[i].r;
        }
        cout<<ri-li<<endl;
    }
    return 0;
}