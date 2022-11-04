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
 

int main()
{
    sync;
    int a,b,c,r,t;
    cin>>t;
    int sa,sb;
    while(t--)
    {
        cin>>a>>b>>c>>r;
        if(a>b)
        swap(a,b);
        int s=b-a,lc,rc;
        lc=c-r;
        rc=c+r;
        if(rc<a||lc>b)
        {
            cout<<s<<endl;
            continue;
        }
        lc=max(lc,a);
        rc=min(rc,b);
        cout<<s-(rc-lc)<<endl;
    }
    return 0;
}