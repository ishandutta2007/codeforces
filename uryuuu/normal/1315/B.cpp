#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;


string s;
int c[5];
int get(char c)
{
    return int(c-'A');
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,p;
        cin>>c[0]>>c[1]>>p;
        cin>>s;
        int n=s.length();
        int sum=n-1;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        int pos=n-2;
        char ss;
        while(pos>=0)
        {
            int id=c[get(s[pos])];
            if(id<=p)
            {
                p-=id;
                ss=s[pos];
                while(s[pos]==ss)
                {
                    pos--;
                    if(pos<0)
                        break;
                }
            }
            else
            {
                break;
            }
            if(pos<0)
                break;
        }
        cout<<pos+2<<endl;
    }
    return 0;
}