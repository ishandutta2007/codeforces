#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

bool solve()
{
    int a=0,b=0;
    string s;cin>>s;
    for(auto i:s)
    {
        if(i=='0')a++;
        else b++;
    }
    a=min(a,b);
    if(a&1)return 1;
    else return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("DA");
        else puts("NET");
    }
}