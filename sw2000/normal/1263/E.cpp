#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int mi[maxn*4]={0},ma[maxn<<2]={0},lazy[maxn*4]={0},arr[maxn]={0},ans[maxn]={0},cnt=1;
int qv;
int ql,qr;
int n,st=1;
char op[maxn]={0};

void update(int o,int l,int r)
{
    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    mi[lo]+=lazy[o];
    ma[lo]+=lazy[o];
    mi[ro]+=lazy[o];
    ma[ro]+=lazy[o];
    lazy[lo]+=lazy[o];
    lazy[ro]+=lazy[o];
    lazy[o]=0;
}

void add(int o,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        mi[o]+=qv;
        ma[o]+=qv;
        lazy[o]+=qv;
        return;
    }

    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    update(o,l,r);

    if(mid>=ql)add(lo,l,mid);
    if(mid<qr)add(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
    ma[o]=max(ma[lo],ma[ro]);
}

int querymin(int o,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        return mi[o];
    }

    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    update(o,l,r);

    int a=inf,b=inf;
    if(mid>=ql)a=querymin(lo,l,mid);
    if(mid<qr)b=querymin(ro,mid+1,r);
    return min(a,b);
}
int querymax(int o,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        return ma[o];
    }

    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    update(o,l,r);

    int a=-inf,b=-inf;
    if(mid>=ql)a=querymax(lo,l,mid);
    if(mid<qr)b=querymax(ro,mid+1,r);
    return max(a,b);
}

void check()
{
//    cout<<endl;
//    cout<<mi[1]<<' ';
    qr=ql=n;
    if(mi[1]<0||querymin(1,1,n)!=0)
    {
        ans[cnt++]=-1;
        return;
    }
    ql=1;
    ans[cnt++]=querymax(1,1,n);
}

int main()
{
    //freopen("in.txt","r",stdin);

    scanf("%d%s",&n,op);
    for(int i=0;i<n;i++)
    {
        //cout<<op<<endl;
        if(op[i]=='R')
        {
            st++;
            ans[cnt]=ans[cnt-1];
            cnt++;
        }
        else if(op[i]=='L')
        {
            if(st!=1)st--;
            ans[cnt]=ans[cnt-1];
            cnt++;
        }
        else
        {
            ql=st,qr=n;
            if(op[i]=='(')
            {
                qv=1-arr[st];
                arr[st]=1;
            }
            else if(op[i]==')')
            {
                qv=-1-arr[st];
                arr[st]=-1;
            }
            else
            {
                qv=-arr[st];
                arr[st]=0;
            }
            add(1,1,n);
            check();
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        if(i!=n)printf(" ");
    }

    return 0;
}