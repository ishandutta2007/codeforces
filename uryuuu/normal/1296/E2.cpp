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
const int maxn=200005;
const ll Mod=1e9+7;

struct node
{
    int mx,id;
}a[maxn];
int b[maxn];
bool cmp(node a,node b)
{
    return a.mx>b.mx;
}
string s;
int main()
{
    sync;
    int n;
    cin>>n>>s;
    int cnt=1;
    a[cnt].mx=int(s[0]-'a')+1;
    a[cnt].id=1;
    b[0]=1;
    int f;
    int l,r,mid,pos;
    for(int i=1;i<n;i++)
    {
        f=0;
        int x=int(s[i]-'a')+1;
        l=1;
        r=cnt;
        if(a[cnt].mx>x)
        {
            a[++cnt].mx=x;
            a[cnt].id=cnt;
            b[i]=cnt;
        }
        else
        {
            while(l<r)
            {
                mid=(l+r)/2;
                if(a[mid].mx>x)
                    l=mid+1;
                else
                    r=mid;
            }
            pos=l;
            a[pos].mx=x;
            b[i]=a[pos].id;
//            cout<<pos<<' '<<a[pos].id<<endl;
        }
        sort(a+1,a+cnt+1,cmp);
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}