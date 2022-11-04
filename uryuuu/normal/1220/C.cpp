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
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;

string s;

int main()
{
    sync;
//    int n;
    cin>>s;
    char c=s[0];
    int n=s.length();
    cout<<"Mike"<<endl;
    for(int i=1;i<n;i++)
    {
        if(c<s[i])
            cout<<"Ann"<<endl;
        else
            cout<<"Mike"<<endl;
        if(s[i]<c)
            c=s[i];
    }
    return 0;
}