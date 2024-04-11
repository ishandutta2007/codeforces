#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int n,k;

bool solve()
{
    for(int i=1;i*i<=k+100;i++)
    {
        if(i-1+k/i+(k%i!=0)<=n)return 1;
    }
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n>>k;
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}