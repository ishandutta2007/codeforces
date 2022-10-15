#include<bits/stdc++.h>
#define MN 100005
using namespace std;
int ans[MN],gs,n,m;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void work(int L,int R,int ql)
{
	if (L==R-1) {ans[L]=ql; return;}
	if (gs)
	{
		int mid=L+R>>1;
		--gs;
		work(L,mid,ql+R-mid);
		work(mid,R,ql);
	}
	else for (int i=0;i<R-L;++i) ans[L+i]=ql+i;
}

int main()
{
	register int i;
    n=read(); m=read();
    if (~m&1) return 0*printf("-1");
    if (m>n*2-1) return 0*printf("-1");
    gs=(m-1)/2;
	work(0,n,1);
	for (i=0;i<n;++i) printf("%d ",ans[i]);
    return 0;
}