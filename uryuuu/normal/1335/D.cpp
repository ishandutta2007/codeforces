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
#include<map>
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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[20][20];
string s;
int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=9;i++)
        {
            cin>>s;
            for(int j=1;j<=9;j++)
            {
                a[i][j]=ch(s[j-1]);
            }
        }
        a[1][1]=a[1][2];
        a[2][4]=a[1][4];
        a[3][7]=a[1][7];
        a[4][2]=a[1][2];
        a[5][5]=a[1][5];
        a[6][8]=a[1][8];
        a[7][3]=a[1][3];
        a[8][6]=a[1][6];
        a[9][9]=a[1][9];
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    
    
    
    
    return 0;
}