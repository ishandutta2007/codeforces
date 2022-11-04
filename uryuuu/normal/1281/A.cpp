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
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        if(n>=2&&s[n-1]=='o'&&s[n-2]=='p')
        {
            cout<<"FILIPINO"<<endl;
            continue;
        }
        if(n>=5&&s[n-1]=='a'&&s[n-2]=='d'&&s[n-3]=='i'&&s[n-4]=='n'&&s[n-5]=='m')
        {
            cout<<"KOREAN"<<endl;
            continue;
        }
        else
            cout<<"JAPANESE"<<endl;
    }
    
    return 0;
}