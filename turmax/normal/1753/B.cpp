#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;cin>>n>>x;int a[n];
    map<int,int> u;
    for(int i=0;i<n;++i) {cin>>a[i];u[a[i]]++;}
    int key=0;
    while(key<x)
    {
        while(!u[key]) ++key;
        if(key>=x) break;
        if(u[key]%(key+1)!=0)
        {
            puts("No");
            return 0;
        }
        u[key+1]+=u[key]/(key+1);
        u[key]=0;
    }
    puts("Yes");
    return 0;
}