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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

string s;
int a[300];
int L[200],R[200];

int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    mm(a);
    for(int i=0;i<n;i++)
    {
        a[i+1]=ch(s[i])+1;
    }
    for(int i=1;i<=n;i++)
    {
        L[i]=i-1;
        R[i]=i+1;
    }
    int f;
    int sum=0;
    for(int k=27;k>=2;k--)
    {
        while(1)
        {
            f=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==k)
                {
                    if(a[L[i]]==a[i]-1||a[R[i]]==a[i]-1)
                    {
                        a[i]=0;
                        f=1;
                        L[R[i]]=L[i];
                        R[L[i]]=R[i];
                        sum++;
                    }
                }
            }
            if(f==0)
                break;
        }
    }
    cout<<sum<<endl;
    return 0;
}