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

int a[maxn],s[maxn],b[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    s[n]=1;
    int da=1;
    for(int i=n-1;i>=1;i--)
    {
        s[i]=1;
        if(a[i]<a[i+1])
            s[i]+=s[i+1];
        da=max(s[i],da);
    }
    b[1]=1;
    for(int i=2;i<=n;i++)
    {
        b[i]=1;
        if(a[i-1]<a[i])
            b[i]+=b[i-1];
        da=max(da,b[i]);
    }
    for(int i=2;i<n;i++)
    {
        if(a[i-1]<a[i+1])
            da=max(da,b[i-1]+s[i+1]);
    }
    cout<<da<<endl;
    return 0;
}