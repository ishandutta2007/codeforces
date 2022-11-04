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
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;

int a[maxn],b[maxn];
int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int pos;
        int l=1,r=n,zx=n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=0;
        }
        int cnt=n;
        while(l<r)
        {
            if(a[l]>a[r])
            {
                zx=min(zx,a[l]);
                l++;
                cnt--;
            }
            else
            {
                zx=min(zx,a[r]);
                r--;
                cnt--;
            }
            if(cnt+1==zx)
            {
                b[zx-1]=1;
            }
        }
        for(int i=1;i<n;i++)
            cout<<b[i];
        cout<<1<<endl;
    }
    return 0;
}