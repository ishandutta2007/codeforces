#include<bits/stdc++.h>

#define pii pair<int,int>
#define tin pair<pii,int>
#define l in[i].first.first
#define r in[i].first.second
#define x in[i].second

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    tin in[m];
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&l,&r,&x),l--,r--,x--;
    int len=sqrt(n)+1;
    int N=len*len;
    int a[N];
    memset(a,255,sizeof(a));
    int b[len];
    memset(b,255,sizeof(b));
    for(int i=m-1;i>=0;i--)
    {
        int tl=l,tr=x-1;
        if(tl<=tr)
        {
            int L=tl/len,R=tr/len;
            if(L==R)
            {
                if(b[L]!=-1)
                {
                    for(int k=L*len;k<(L+1)*len;k++)
                        a[k]=b[L];
                    b[L]=-1;
                }
                for(int k=tl;k<=tr;k++)
                    a[k]=x;
            }
            else
            {
                if(b[L]!=-1)
                {
                    for(int k=L*len;k<(L+1)*len;k++)
                        a[k]=b[L];
                    b[L]=-1;
                }
                if(b[R]!=-1)
                {
                    for(int k=R*len;k<(R+1)*len;k++)
                        a[k]=b[R];
                    b[R]=-1;
                }
                for(int k=tl;k<(L+1)*len;k++)
                    a[k]=x;
                for(int k=R*len;k<=tr;k++)
                    a[k]=x;
                for(int k=L+1;k<=R-1;k++)
                    b[k]=x;
            }
        }
        tl=x+1,tr=r;
        if(tl<=tr)
        {
            int L=tl/len,R=tr/len;
            if(L==R)
            {
                if(b[L]!=-1)
                {
                    for(int k=L*len;k<(L+1)*len;k++)
                        a[k]=b[L];
                    b[L]=-1;
                }
                for(int k=tl;k<=tr;k++)
                    a[k]=x;
            }
            else
            {
                if(b[L]!=-1)
                {
                    for(int k=L*len;k<(L+1)*len;k++)
                        a[k]=b[L];
                    b[L]=-1;
                }
                if(b[R]!=-1)
                {
                    for(int k=R*len;k<(R+1)*len;k++)
                        a[k]=b[R];
                    b[R]=-1;
                }
                for(int k=tl;k<(L+1)*len;k++)
                    a[k]=x;
                for(int k=R*len;k<=tr;k++)
                    a[k]=x;
                for(int k=L+1;k<=R-1;k++)
                    b[k]=x;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",((b[i/len]==-1)?a[i]:b[i/len])+1);
}