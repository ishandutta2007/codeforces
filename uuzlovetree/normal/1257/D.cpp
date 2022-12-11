#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int T,n,m;
int st[maxn][20],maxhp[maxn];
struct node
{
	int atk,hp;
}a[maxn];
int b[maxn]; 
bool operator < (node A,node B){return A.atk<B.atk;}
void init()
{
	for(int j=1;j<=19;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int getmax(int l,int r)
{
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&st[i][0]);
		init();
		scanf("%d",&m);
		for(int i=1;i<=m;++i)scanf("%d%d",&a[i].atk,&a[i].hp);
		sort(a+1,a+m+1);
		for(int i=1;i<=m;++i)b[i]=a[i].atk;
		maxhp[m+1]=0; 
		for(int i=m;i>=1;--i)maxhp[i]=max(maxhp[i+1],a[i].hp);
		int pos=0,ans=0;
		while(pos<n)
		{
			int l=pos+1,r=n,res=pos;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int maxv=getmax(pos+1,mid),len=mid-pos;
				int x=lower_bound(b+1,b+m+1,maxv)-b;
				if(maxhp[x]>=len)res=mid,l=mid+1;
				else r=mid-1;
			}
			if(res==pos){ans=-1;break;}
			ans++;pos=res;
		}
		printf("%d\n",ans);
	}
}