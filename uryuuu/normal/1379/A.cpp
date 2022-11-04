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
//#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn = 300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

string s;
string a;;

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    a="abacaba";
    while(t--)
    {
        cin>>n;
        cin>>s;
        int f=0,fl;
        for(int i=0;i+7<=n;i++)
        {
            fl=0;
            for(int j=0;j<7;j++)
            {
                if(s[i+j]!=a[j])
                    fl=1;
            }
            if(fl==0)
                f++;
        }
        if(f>1)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(f==1)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='?')
                    cout<<'z';
                else
                    cout<<s[i];
            }
            cout<<endl;
            continue;
        }
        for(int i=0;i+7<=n;i++)
        {
            fl=0;
            for(int j=0;j<7;j++)
            {
                if(s[i+j]!=a[j]&&s[i+j]!='?')
                    fl=1;
            }
            if(fl==0)
            {
                if(i+11<=n&&s[i+7]=='c'&&s[i+8]=='a'&&s[i+9]=='b'&&s[i+10]=='a')
                    continue;
                if(i-4>=0&&s[i-1]=='c'&&s[i-2]=='a'&&s[i-3]=='b'&&s[i-4]=='a')
                    continue;
                if(i+13<=n&&s[i+7]=='b'&&s[i+8]=='a'&&s[i+9]=='c'&&s[i+10]=='a'&&s[i+11]=='b'&&s[i+12]=='a')
                    continue;
                if(i-6>=0&&s[i-1]=='b'&&s[i-2]=='a'&&s[i-3]=='c'&&s[i-4]=='a'&&s[i-5]=='b'&&s[i-6]=='a')
                    continue;
                for(int j=0;j<7;j++)
                {
                    s[i+j]=a[j];
                }
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='?')
                    cout<<'z';
                else
                    cout<<s[i];
            }
            cout<<endl;
        }
        
        
    }
    
    return 0;
}