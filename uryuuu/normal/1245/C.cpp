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
const int maxn=100005;
const ll Mod=1000000007;

string s;
ll a[maxn];
int main()
{
    sync;
    cin>>s;
    int n=s.length();
    int sum=0;
    a[0]=1;
    for(int i=0;i<n;i++)
    {
        a[i+1]+=a[i];
        if((s[i]=='u'&&s[i+1]=='u')||(s[i]=='n'&&s[i+1]=='n'))
        {
            a[i+2]=(a[i+2]+a[i])%Mod;
        }
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<a[n]%Mod;
    cout<<endl;
    return 0;
}