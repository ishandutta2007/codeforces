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
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
string s;

int main()
{
    sync;
    int a,b;
    cin>>a>>b;
    if(a==b-1)
        cout<<a<<9<<' '<<b<<0<<endl;
    else if(a==b)
        cout<<a<<1<<' '<<b<<2<<endl;
    else if(a==9&&b==1)
        cout<<a<<' '<<10<<endl;
    else
        cout<<-1<<endl;
    return 0;
}