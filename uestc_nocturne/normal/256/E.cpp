/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=80000;
const int P=777777777;
int Mat[50][3][3];
void init()
{
    for(int s=1;s<20;s++)
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            Mat[s][i][j]=0;
            for(int k=0;k<3;k++)
            {
                Mat[s][i][j]+=(LL)Mat[s-1][i][k]*Mat[s-1][k][j]%P;
                if(Mat[s][i][j]>=P)Mat[s][i][j]-=P;
            }
        }
       // for(int i=0;i<3;i++,puts(""))for(int j=0;j<3;j++)printf("%d ",Mat[s][i][j]);
    }
}
struct Node
{
    int l,r,way;
    int sl,sr,idl,idr;
    bool all;
}p[4*V];
void init(int nu,int l,int r)
{
    p[nu].l=l;
    p[nu].r=r;
    p[nu].all=1;
    p[nu].way=1;
    if(l==r)return;
    int mid=(l+r)/2;
    init(nu*2,l,mid);
    init(nu*2+1,mid+1,r);
}
void Up(int nu)
{
    if(p[nu*2].all&&p[nu*2+1].all)
    p[nu].all=1;
    else p[nu].all=0;
    if(p[nu].all==1){p[nu].way=1;return;}
    int mid=(p[nu].l+p[nu].r)/2;
    if(p[nu*2].all)
    {
        p[nu].sl=mid-p[nu].l+1+p[nu*2+1].sl;
        p[nu].idl=p[nu*2+1].idl;
    }
    else
    {
        p[nu].sl=p[nu*2].sl;
        p[nu].idl=p[nu*2].idl;
    }
    if(p[nu*2+1].all)
    {
        p[nu].sr=p[nu].r-mid+p[nu*2].sr;
        p[nu].idr=p[nu*2].idr;
    }
    else
    {
        p[nu].sr=p[nu*2+1].sr;
        p[nu].idr=p[nu*2+1].idr;
    }
    p[nu].way=(LL)p[nu*2].way*p[nu*2+1].way%P;
    if(!p[nu*2].all&&!p[nu*2+1].all)
    {
        int d=p[nu*2].sr+p[nu*2+1].sl+1;
        int tmp[2][3][3];
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(i!=j)tmp[0][i][j]=0;
        else tmp[0][i][j]=1;
        int fl=0,te=1,t=0;
        while(d)
        {
            if(d&1)
            {
                te=1-fl;
                for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                {
                    tmp[te][i][j]=0;
                    for(int k=0;k<3;k++)
                    {
                        tmp[te][i][j]+=(LL)tmp[fl][i][k]*Mat[t][k][j]%P;
                        if(tmp[te][i][j]>=P)tmp[te][i][j]-=P;
                    }
                }
                fl=te;
            }
            d/=2;t++;
        }
        p[nu].way=(LL)p[nu].way*tmp[fl][p[nu*2].idr-1][p[nu*2+1].idl-1]%P;
    }
}
void update(int nu,int po,int x)
{
    if(p[nu].l==po&&p[nu].r==po)
    {
        p[nu].way=1;
        if(x==0)p[nu].all=1;
        else
        {
            p[nu].all=0;
            p[nu].idl=x;
            p[nu].idr=x;
            p[nu].sl=p[nu].sr=0;
        }
        return;
    }
    int mid=(p[nu].l+p[nu].r)/2;
    if(po<=mid)update(nu*2,po,x);
    else update(nu*2+1,po,x);
    Up(nu);
}
int ss[][3]={{0,0,1},{1,0,1},{0,0,1}};
int n,Q,x,y;
int main()
{
    bool ck=false;
    while(~scanf("%d%d",&n,&Q))
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        scanf("%d",&Mat[0][i][j]);
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(Mat[0][i][j]!=ss[i][j])ck=true;
        init();
        init(1,1,n);
        while(Q--)
        {
            scanf("%d%d",&x,&y);
            update(1,x,y);
            int ans=1;
       //     printf("%d %d %d %d %d %d\n",p[1].all,p[1].sl,p[1].idl,p[1].sr,p[1].idr,p[1].way);
            if(!p[1].all)
            {
                int d=p[1].sl;
                int tmp[2][3][3];
                for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                if(i!=j)tmp[0][i][j]=0;
                else tmp[0][i][j]=1;
                int fl=0,te=1,t=0;
                while(d)
                {
                    if(d&1)
                    {
                        te=1-fl;
                        for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                        {
                            tmp[te][i][j]=0;
                            for(int k=0;k<3;k++)
                            {
                                tmp[te][i][j]+=(LL)tmp[fl][i][k]*Mat[t][k][j]%P;
                                if(tmp[te][i][j]>=P)tmp[te][i][j]-=P;
                            }
                        }
                        fl=te;
                    }
                    d/=2;t++;
                }
                ans=((LL)tmp[fl][0][p[1].idl-1]+tmp[fl][1][p[1].idl-1]
                    +tmp[fl][2][p[1].idl-1])%P*ans%P;

        //      cout<<"a "<<ans<<endl;
                d=p[1].sr;
                for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                if(i!=j)tmp[0][i][j]=0;
                else tmp[0][i][j]=1;
                fl=0,te=1,t=0;
                while(d)
                {
                    if(d&1)
                    {
                        te=1-fl;
                        for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                        {
                            tmp[te][i][j]=0;
                            for(int k=0;k<3;k++)
                            {
                                tmp[te][i][j]+=(LL)tmp[fl][i][k]*Mat[t][k][j]%P;
                                if(tmp[te][i][j]>=P)tmp[te][i][j]-=P;
                            }
                        }
                        fl=te;
                    }
                    d/=2;t++;
                }
            //    cout<<"b "<<ans<<endl;
                ans=((LL)tmp[fl][p[1].idr-1][0]+tmp[fl][p[1].idr-1][1]
                    +tmp[fl][p[1].idr-1][2])%P*ans%P;
            //    cout<<"c "<<ans<<endl;
                ans=(LL)ans*p[1].way%P;
            }
            else
            {
                ans=0;
                int d=n-1;
                int tmp[2][3][3];
                for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                if(i!=j)tmp[0][i][j]=0;
                else tmp[0][i][j]=1;
                int fl=0,te=1,t=0;
                while(d)
                {
                    if(d&1)
                    {
                        te=1-fl;
                        for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                        {
                            tmp[te][i][j]=0;
                            for(int k=0;k<3;k++)
                            {
                                tmp[te][i][j]+=(LL)tmp[fl][i][k]*Mat[t][k][j]%P;
                                if(tmp[te][i][j]>=P)tmp[te][i][j]-=P;
                            }
                        }
                        fl=te;
            //  for(int i=0;i<3;i++,puts(""))for(int j=0;j<3;j++)printf("%d ",Mat[t][i][j]);
            //  for(int i=0;i<3;i++,puts(""))for(int j=0;j<3;j++)printf("%d ",tmp[fl][i][j]);
                    }
                    d/=2;t++;
                }
                for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                ans=(ans+tmp[fl][i][j])%P;
            }
            printf("%d\n",ans);
        }
    }
}