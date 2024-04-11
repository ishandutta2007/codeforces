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
const ll  Mod=998244353;

string a[30],b[30];
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int q;
    cin>>q;
    int d;
    int mmm=0;
    while(q--)
    {
        cin>>d;
//        cout<<mmm++<<endl;
        cout<<a[(d-1)%n]<<b[(d-1)%m]<<endl;
    }
    
    
    
    return 0;
}