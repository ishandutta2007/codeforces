#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int sum[15][1<<18][5];
int sum_tag[15][100005];
int sum_max[15][15];
inline int decode(char x)
{
    if (x=='A') return 0;
    if (x=='C') return 1;
    if (x=='G') return 2;
    if (x=='T') return 3;
    return -1;
}
void change_node(int num,int t1,int l,int r,int l0,int r0,int code,int k)
{
    if ((l0<=l)&&(r<=r0))
    {
        sum[t1][num][code]+=k;
        return;
    }
    int mid=(l+r)/2;
    if (l0<mid) change_node(num*2+1,t1,l,mid,l0,r0,code,k);
    if (mid<r0) change_node(num*2+2,t1,mid,r,l0,r0,code,k);
}
int query(int num,int t1,int l,int r,int x,int code)
{
    if (x==-1) return 0;
    if (l==r-1)
    {
        return sum[t1][num][code];
    }
    int mid=(l+r)/2;
    if (x<mid)
    {
        return sum[t1][num][code]+query(num*2+1,t1,l,mid,x,code);
    }
    else
    {
        return sum[t1][num][code]+query(num*2+2,t1,mid,r,x,code);
    }
}
int finds(int x,int y,int z)
{
    for (;;)
    {
        x--;
        if (x<0) return -1;
        if (x%y==z) return x;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    int i;
    for (i=1;i<=10;i++)
    {
        int j;
        int sum=0;
        for (j=0;j<i;j++)
        {
            int k;
            static int tags[5];
            memset(tags,0,sizeof(tags));
            for (k=j;k<n;k+=i)
            {
                tags[decode(s[k])]++;
                sum_tag[i][k]=sum;
                int l;
                for (l=0;l<4;l++)
                {
                    change_node(0,i,0,n,sum,sum+1,l,tags[l]);
                }
                sum++;
            }
            sum_max[i][j]=sum;
        }
    }
    int q;
    cin>>q;
    for (i=0;i<q;i++)
    {
        int oper;
        cin>>oper;
        if (oper==1)
        {
            int x;
            char c;
            cin>>x>>c;
            x--;
            int j;
            for (j=1;j<=10;j++)
            {
                change_node(0,j,0,n,sum_tag[j][x],sum_max[j][x%j],decode(s[x]),-1);
                change_node(0,j,0,n,sum_tag[j][x],sum_max[j][x%j],decode(c),1);
            }
            s[x]=c;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l--;
            string t;
            cin>>t;
            int m=t.length();
            int j;
            int ans=0;
            for (j=0;j<m;j++)
            {
                int t1=finds(r,m,(l+j)%m);
                if (t1!=-1) ans+=query(0,m,0,n,sum_tag[m][t1],decode(t[j]));
                int t2=finds(l,m,(l+j)%m);
                if (t2!=-1) ans-=query(0,m,0,n,sum_tag[m][t2],decode(t[j]));
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}