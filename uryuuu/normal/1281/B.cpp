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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;



int main()
{
    sync;
    int t;
    string s,c,ss;
    cin>>t;
    while(t--)
    {
        cin>>s>>c;
        int ls=s.length();
        int lc=c.length();
        ss=s;
        sort(ss.begin(),ss.end());
        int f=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>ss[i])
            {
                for(int j=s.length()-1;j>i;j--)
                {
                    if(s[j]==ss[i])
                    {
                        swap(s[i],s[j]);
                        f=1;
                        break;
                    }
                }
                if(f)
                    break;
            }
        }
        if(s<c)
            cout<<s<<endl;
        else
            cout<<"---"<<endl;
    }
    return 0;
}