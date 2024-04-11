#include <bits/stdc++.h>

using namespace std;
#define int long long
map<int,int> answ;
map<int,int> u;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        char s;int k;cin>>s>>k;
        if(s=='+') {u[k]++;}
        else {while(u[answ[k]+k]) answ[k]+=k; cout<<answ[k]+k<<'\n';}
    }
    return 0;
}