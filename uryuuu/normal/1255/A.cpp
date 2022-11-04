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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int s[10];
int main()
{
    sync;
    
    int t;
    int a,b;
    cin>>t;
    s[0]=0;
    s[1]=1;
    s[2]=1;
    s[3]=2;
    s[4]=2;
    int ss;
    while(t--)
    {
        cin>>a>>b;
        if(a==b)
            cout<<0<<endl;
        else
        {
            int d=abs(a-b);
            ss=d/5;
            ss+=s[d%5];
            cout<<ss<<endl;
        }
    }
    return 0;
}