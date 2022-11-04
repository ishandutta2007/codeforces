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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;

string s;
int a[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            a[i+1]=1;
            k++;
        }
        else
            a[i+1]=-1;
    }
    if(n-k!=k)
    {
        cout<<-1<<endl;
        return 0;
    }
    int pos=1;
    int st,ed;
    int sum=0;
    int s=0;
    while(pos<=n)
    {
        s+=a[pos];
        if(s<0)
        {
            st=pos;
            pos++;
            while(pos<=n)
            {
                s+=a[pos];
                if(s==0)
                {
                    sum+=pos-st+1;
//                    cout<<pos<<' '<<st<<endl;
                    break;
                }
                pos++;
            }
        }
        pos++;
    }
    cout<<sum<<endl;
    
    return 0;
}