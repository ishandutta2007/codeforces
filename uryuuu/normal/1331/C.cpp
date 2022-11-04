#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400010;;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int a[10];
int main()
{
    int x;
    cin>>x;
    for(int i=5;i>=0;i--)
    {
        if(x>=(1<<i))
        {
            a[i]=1;
            x-=(1<<i);
        }
        else
            a[i]=0;
    }
    int s=(a[5]<<5)+(a[4])+(a[3]<<2)+(a[2]<<3)+(a[1]<<1)+(a[0]<<4);
    cout<<s<<endl;
    return 0;
}