#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1e9+7;


string s;
int a[300005];

int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int l=n-1,r=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<i)
            {
                l=i-1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]<n-1-i)
            {
                r=i+1;
                break;
            }
        }
        if(l>=r)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}