#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct mat
{
	int a[6][6];
	void init()
	{
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
				a[i][j]=1e9;
	}
}tr[N<<2];
int n,q;
char s[N];
mat operator*(mat x,mat y)
{
	mat z;
	z.init();
	for(int i=1;i<=5;i++)
		for(int k=1;k<=5;k++)
			for(int j=1;j<=5;j++)
				if(z.a[i][j]>x.a[i][k]+y.a[k][j])
					z.a[i][j]=x.a[i][k]+y.a[k][j];
	return z;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k].init();
		for(int i=1;i<=5;i++)
			tr[k].a[i][i]=0;
		if(s[l]=='0') tr[k].a[2][3]=0,tr[k].a[2][2]=1;
		if(s[l]=='1') tr[k].a[3][4]=0,tr[k].a[3][3]=1;
		if(s[l]=='2') tr[k].a[1][2]=0,tr[k].a[1][1]=1;
		if(s[l]=='6') tr[k].a[4][4]=1,tr[k].a[5][5]=1;
		if(s[l]=='7') tr[k].a[4][5]=0,tr[k].a[4][4]=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]*tr[k<<1|1];
}
mat query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return query(k<<1,l,mid,a,mid)*query(k<<1|1,mid+1,r,mid+1,b);
}
int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	build(1,1,n);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		mat ans=query(1,1,n,l,r);
		printf("%d\n",ans.a[1][5]==1e9?-1:ans.a[1][5]);
	}
	return 0;
}