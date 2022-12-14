#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=2147493647;

int arr[maxn],c[maxn];
int n,m;

struct A
{
    int a,id;
}a[maxn];

struct B
{
    int k,p,id,ans;
}b[maxn];

bool cmp(A a,A b)
{
    if(a.a!=b.a)return a.a>b.a;
    return a.id<b.id;
}

int lb(int a)
{
    return a&(-a);
}

void add(int a)
{
    for(int i=a;i<=n;i+=lb(i))
        c[i]++;
}

int sum(int a)
{
    int ret=0;
    for(int i=a;i;i-=lb(i))
        ret+=c[i];
    return ret;
}

int fd(int a)
{
    int l=0,r=n;
    while(l+1!=r)
    {
        int mid=r+l>>1;
        if(sum(mid)<a)l=mid;
        else r=mid;
    }
    return l+1;
}

//bool cmp(int a,int b);

int main()
{
    //freopen("in.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        a[i].a=arr[i];
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i].a<<' '<<a[i].id<<endl;
//    }

    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&b[i].k,&b[i].p);
        b[i].id=i;
    }
    sort(b,b+m,[](B a,B b){return a.k<b.k;});

//    for(int i=0;i<m;i++)
//    {
//        cout<<b[i].k<<' '<<b[i].p<<endl;
//    }

    for(int i=0,st=0;i<m;i++)
    {
        while(b[i].k>st)
        {
            add(a[++st].id);
        }

//        for(int i=1;i<=7;i++)
//        {
//            cout<<c[i]<<' ';
//        }
//        cout<<endl;

        int id=fd(b[i].p);
//        cout<<i<<' '<<id<<endl;
        b[i].ans=arr[id];
    }
    sort(b,b+m,[](B a,B b){return a.id<b.id;});

    for(int i=0;i<m;i++)
    {
        printf("%d\n",b[i].ans);
    }

    return 0;
}