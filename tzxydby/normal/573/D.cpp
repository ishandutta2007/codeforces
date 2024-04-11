#include<bits/stdc++.h>
using namespace std;
const int N=30005;
int n,q,p[N],c[N];
struct data
{
    int id;
	long long x;
    bool operator <(const data&b)const
	{
		return x<b.x;
	}
}a[N],b[N];
bool ck(int x,int y){return p[a[x].id]!=b[y].id;}
struct matrix
{
    long long s[3][3];
    matrix operator *(const matrix&b)
	{
        matrix c;memset(c.s,192,sizeof(c.s));
        for(int i=0;i<3;i++)
        	for(int j=0;j<3;j++)
        		for(int k=0;k<3;k++)
					c.s[i][j]=max(c.s[i][j],s[i][k]+b.s[k][j]);
        return c;
    }
    inline void update(int x)
	{
        memset(s,192,sizeof(s));
		s[0][1]=s[1][2]=0;
        if(ck(x,x))s[0][0]=a[x].x*b[x].x;
        if(x>1&&ck(x,x-1)&&ck(x-1,x))
			s[1][0]=a[x].x*b[x-1].x+a[x-1].x*b[x].x;
        if(x>2)
		{
            if(ck(x,x-2)&&ck(x-1,x)&&ck(x-2,x-1))
				s[2][0]=a[x].x*b[x-2].x+a[x-1].x*b[x].x+a[x-2].x*b[x-1].x;
            if(ck(x,x-1)&&ck(x-1,x-2)&&ck(x-2,x))
				s[2][0]=max(s[2][0],a[x].x*b[x-1].x+a[x-1].x*b[x-2].x+a[x-2].x*b[x].x);
        }
    }
}tree[N*4];
void update(int k,int l=1,int r=n,int p=1)
{
    if(l==r)
		return tree[p].update(l);
	int mid=l+r>>1;
    if(k<=mid)
		update(k,l,mid,p<<1);
	else 
		update(k,mid+1,r,p<<1|1);
    tree[p]=tree[p<<1]*tree[p<<1|1];
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i].x),a[i].id=i,p[i]=i;
    for(int i=1;i<=n;i++)
		scanf("%I64d",&b[i].x),b[i].id=i;
    sort(a+1,a+1+n);sort(b+1,b+1+n);for(int i=1;i<=n;i++)c[a[i].id]=i;
    for(int i=1;i<=n;i++)
		update(i);
    while(q--)
	{
        int x,y;
		scanf("%d%d",&x,&y);
		swap(p[x],p[y]);
        for(int i=c[x];i<c[x]+3;i++)
			update(i);
		for(int i=c[y];i<c[y]+3;i++)
			update(i);
        printf("%I64d\n",tree[1].s[0][0]);
    }
    return 0;
}