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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
const ll Mod=1e9+7;
using namespace std;

string s;
int main()
{
    sync
    cin>>s;
    int len=s.length();
    if(len==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(len%2==0)
    {
        cout<<len/2<<endl;
        return 0;
    }
    int f=0;
    for(int i=len-1;i>0;i--)
    {
        if(s[i]=='1')
            f=1;
    }
    if(f==1)
        cout<<len/2+1;
    else
        cout<<len/2<<endl;
    return 0;
}