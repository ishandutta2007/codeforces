#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
inline int lb(int a){return a&(-a);}

int n,c[4][maxn<<2];
struct A
{
    int a,b,c,d;
}arr[maxn],brr[maxn];
map<int,int>m;

void add(int o,int p,int v)
{
    for(int i=p;i<(maxn<<2);i+=lb(i))
        c[o][i]+=v;
}

int query(int o,int p)
{
    int ret=0;
    for(int i=p;i;i-=lb(i))
        ret+=c[o][i];
    return ret;
}

void push(A a)
{
    add(2,a.c,1);
    add(3,a.d,1);
    add(0,a.c,-1);
    add(1,a.d,-1);
}
void pull(A a)
{
    add(2,a.c,-1);
    add(3,a.d,-1);
}

bool solve()
{
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&brr[j].b>=arr[i].a)
        {
            push(brr[j]);
            j++;
        }
        pull(arr[i]);
        if(query(3,arr[i].c-1)||query(2,arr[i].d)!=query(2,(maxn<<2)-1))
        {
            return 0;
        }
        if(query(0,arr[i].c-1)!=query(1,arr[i].c-1)||query(0,arr[i].d)!=query(1,arr[i].d))return 0;
        if(query(0,arr[i].c-1)!=query(0,arr[i].d)||query(1,arr[i].c-1)!=query(1,arr[i].d))return 0;
    }
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a[4];
        for(int j=0;j<4;j++)
        {
            scanf("%d",a+j);
            m[a[j]]=1;
        }
        arr[i]={a[0],a[1],a[2],a[3]};
    }
    int cnt=1;
    for(auto &i:m)
    {
        i.second=cnt;
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        arr[i].a=m[arr[i].a];
        arr[i].b=m[arr[i].b];
        arr[i].c=m[arr[i].c];
        arr[i].d=m[arr[i].d];
        brr[i]=arr[i];
        add(0,arr[i].c,1);
        add(1,arr[i].d,1);
    }
    sort(arr+1,arr+n+1,[](A a,A b){return a.a>b.a;});
    sort(brr+1,brr+n+1,[](A a,A b){return a.b>b.b;});
    if(solve())puts("YES");
    else puts("NO");
    return 0;
}