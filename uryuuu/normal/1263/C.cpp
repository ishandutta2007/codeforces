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
const int maxn=200005;
 
int a[2000005];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=1;
        a[0]=0;
        a[cnt++]=1;
        if(n!=1)
            a[cnt++]=n;
        for(int i=1;i*i<=n;i++)
        {
            if(n/i!=a[cnt-1]&&n/i!=a[cnt-2])
            {
                if(i==n/i)
                    a[cnt++]=i;
                else
                {
                    a[cnt++]=i;
                    a[cnt++]=n/i;
                }
            }
        }
        sort(a,a+cnt);
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}