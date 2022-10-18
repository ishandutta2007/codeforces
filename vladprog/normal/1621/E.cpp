#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

struct frac
{
    int a,b;
    frac(int a_=0,int b_=1):a(a_),b(b_){}
};
#define def(op) \
bool operator op(frac x,frac y) \
{ \
    return x.a*y.b op y.a*x.b; \
}
def(==)
def(!=)
def(>)
def(<)
def(>=)
def(<=)
#undef def

struct student
{
    int age;
    int id;
};

struct group
{
    int sum;
    frac avg;
    vector<student>*st;
};
#define def(op) \
bool operator op(group x,group y) \
{ \
    return x.avg op y.avg; \
}
def(==)
def(!=)
def(>)
def(<)
def(>=)
def(<=)
#undef def

#define def(op) \
bool operator op(group x,frac y) \
{ \
    return x.avg op y; \
}
def(==)
def(!=)
def(>)
def(<)
def(>=)
def(<=)
#undef def

#define def(op) \
bool operator op(frac x,group y) \
{ \
    return x op y.avg; \
}
def(==)
def(!=)
def(>)
def(<)
def(>=)
def(<=)
#undef def

const int N=1e5+100,K=2e5+100;

int a[N];
group b[N];
bool ans[K];

int now_sum[N];
int now(int l,int r)
{
    return now_sum[r]-now_sum[l-1];
}

int lef_sum[N];
int lef(int l,int r)
{
    return lef_sum[r]-lef_sum[l-1];
}

int rig_sum[N];
int rig(int l,int r)
{
    return rig_sum[r]-rig_sum[l-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1,greater<>());
        #define n weoigjewiorg
        int t=0;
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            b[i].sum=0;
            b[i].st=new vector<student>(k);
            for(int j=0;j<k;j++)
                cin>>(*b[i].st)[j].age,
                (*b[i].st)[j].id=++t,
                b[i].sum+=(*b[i].st)[j].age;
            b[i].avg=frac(b[i].sum,b[i].st->size());
        }
        sort(b+1,b+m+1,greater<>());
        now_sum[0]=0;
        for(int i=1;i<=m;i++)
            now_sum[i]=now_sum[i-1]+(a[i]<b[i].avg);
        lef_sum[0]=lef_sum[1]=0;
        for(int i=2;i<=m;i++)
            lef_sum[i]=lef_sum[i-1]+(a[i]<b[i-1].avg);
        rig_sum[0]=0;
        for(int i=1;i<=m-1;i++)
            rig_sum[i]=rig_sum[i-1]+(a[i]<b[i+1].avg);
        rig_sum[m]=rig_sum[m-1];
        for(int i=1;i<=m;i++)
        {
            for(auto s:*b[i].st)
            {
                frac avg(b[i].sum-s.age,b[i].st->size()-1);
                int p=lower_bound(b+1,b+m+1,avg,greater<>())-b;
                if(p>i)
                    p--;
                if(p<i)
                    ans[s.id]=!now(1,p-1)&&(avg<=a[p])&&!lef(p+1,i)&&!now(i+1,m);
                else
                    ans[s.id]=!now(1,i-1)&&!rig(i,p-1)&&(avg<=a[p])&&!now(p+1,m);
            }
        }
        for(int i=1;i<=t;i++)
            cout<<ans[i];
        cout<<"\n";
        for(int i=1;i<=m;i++)
            delete b[i].st;
    }
}