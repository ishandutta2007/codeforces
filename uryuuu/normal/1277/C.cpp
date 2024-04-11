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
typedef pair<int,int> pii;
const int maxn=200005;
const ll Mod=1000000007;

string s;
int a[maxn];


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>s;
        int n=s.length();
        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
            {
                if(i+4<n)
                {
                    if(s[i+3]=='n'&&s[i+4]=='e')
                    {
                        a[cnt++]=i+2+1;
                        s[i+2]='g';
                    }
                    else
                    {
                        a[cnt++]=i+2;
                        s[i+1]='g';
                    }
                }
                else
                {
                    a[cnt++]=i+2;
                    s[i+1]='g';
                }
            }
            else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
            {
                a[cnt++]=i+1+1;
                s[i+1]='g';
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}