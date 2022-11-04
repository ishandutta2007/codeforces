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
int main()
{
    sync;
    ll n,c,sum;
    cin>>n;
    ll d,e;
    ll s;
    while(n--)
    {
        cin>>c>>sum;
        d=sum/c;
        e=sum%c;
        s=(c-e)*d*d+e*(d+1)*(d+1);
        cout<<s<<endl;
    }
    return 0;
}