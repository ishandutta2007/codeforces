#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL ooo=1000000001;
const LL oo=ooo*ooo;
const int V=100100;
struct Node{LL l,r;}q[V];
bool LE(Node x,Node y)
{return x.l<y.l;}
bool RI(Node x,Node y)
{return x.r<y.r;}
int n,N,i,j,ct;
LL k;
LL p[V*10];
LL le[V*10],ri[V*10];
int main()
{
    while(cin>>n>>k)
    {
        LL mi=oo;
        for(i=0;i<n;i++)
        {
            cin>>q[i].l>>q[i].r;
            mi=min(mi,q[i].r-q[i].l);
        }
        ct=0;
        for(N=1;N<=18;N++)
        {
            for(i=0;i<(1<<N);i++)
            {
                LL te=0;
                for(j=0;j<N;j++)
                {
                    te*=10;
                    if(i&(1<<j))te+=4;
                    else te+=7;
                }
                p[ct++]=te;
            }
        }
        sort(p,p+ct);
        sort(q,q+n,LE);
        int pt=n-1;
        le[ct-1]=0;
        while(pt>=0&&p[ct-1]<q[pt].l)
        {
            if(oo-le[ct-1]<q[pt].l-p[ct-1])
            le[ct-1]=oo;
            else le[ct-1]+=q[pt].l-p[ct-1];
            pt--;
        }
        for(i=ct-2;i>=0;i--)
        {
            le[i]=le[i+1];
            if((double)(oo-le[i])<(double)(n-1-pt)*(p[i+1]-p[i]))
            le[i]=oo;
            else le[i]+=(n-1-pt)*(p[i+1]-p[i]);
            while(pt>=0&&p[i]<q[pt].l)
            {
                if(oo-le[i]<q[pt].l-p[i])
                le[i]=oo;
                else le[i]+=q[pt].l-p[i];
                pt--;
            }
        }
        sort(q,q+n,RI);
        pt=0;
        ri[0]=0;
        while(pt<n&&p[0]>q[pt].r)
        {
            if(oo-ri[0]<p[0]-q[pt].r)
            ri[0]=oo;
            else ri[0]+=p[0]-q[pt].r;
            pt++;
        }
        for(i=1;i<ct;i++)
        {
            ri[i]=ri[i-1];
            if((double)(oo-ri[i])<(double)(pt)*(p[i]-p[i-1]))
            ri[i]=oo;
            else ri[i]+=(pt)*(p[i]-p[i-1]);
            while(pt<n&&p[i]>q[pt].r)
            {
                if(oo-ri[i]<p[i]-q[pt].r)
                ri[i]=oo;
                else ri[i]+=p[i]-q[pt].r;
                pt++;
            }
        }
    //  for(i=0;i<10;i++)cout<<ri[i]<<" ";puts("");
        int ans=0;
        pt=0;
        for(i=0;i<ct;i++)
        {
            if(le[i]==oo)continue;
            int lo,up,mid;
            while(pt<ct&&p[i]>=p[pt]-mi)pt++;
            lo=i-1;up=pt;
            while(lo+1<up)
            {
                mid=(lo+up)/2;
                if(ri[mid]==oo||le[i]>k-ri[mid])up=mid;
                else lo=mid;
            }
        //  if(i!=lo+1)//printf("%d %d %lld %lld\n",i,lo,le[i],ri[lo]);
        //  printf("%d %d %lld %lld\n",i,pt,p[i],p[pt]);
            ans=max(ans,lo-i+1);
        }
        printf("%d\n",ans);
    }
}