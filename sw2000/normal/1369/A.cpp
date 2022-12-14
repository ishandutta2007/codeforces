#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=2e6+10;
const double PI=acos(0)*2;

bool solve()
{
    int n;scanf("%d",&n);
    if(n%4)return 0;
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
}