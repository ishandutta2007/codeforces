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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[20];
string s;

int main()
{
    sync;
    int t;
    cin>>t;
    for(int i=0;i<10;i++)
        a[i]=-1;
    a[0]=0;
    a[1]=1;
    a[2]=5;
    a[5]=2;
    a[8]=8;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        int H,M;
        cin>>s;
        H=int(s[0]-'0')*10+int(s[1]-'0');
        M=int(s[3]-'0')*10+int(s[4]-'0');
        int fh,fm;
        int h1,h2,m1,m2;
        for(int i=1;i<=100000;i++)
        {
//            cout<<H<<' '<<M<<endl;
            h1=H/10;
            h2=H%10;
            m1=M/10;
            m2=M%10;
            if(a[h1]<0||a[h2]<0||a[m1]<0||a[m2]<0)
            {
                M++;
                if(M==m)
                {
                    M=0;
                    H=(H+1)%h;
                }
                continue;
            }
            fh=a[m2]*10+a[m1];
            fm=a[h2]*10+a[h1];
            if(fh<h&&fm<m)
            {
//                cout<<h1<<' '<<h2<<' '<<m1<<' '<<m2<<' ';
//                cout<<fh<<' '<<fm<<endl;
                break;
            }
            M++;
            if(M==m)
            {
                M=0;
                H=(H+1)%h;
            }
        }
        if(H<=9)
            cout<<0;
        cout<<H;
        cout<<':';
        if(M<=9)
            cout<<0;
        cout<<M<<endl;
    }
    
    return 0;
}