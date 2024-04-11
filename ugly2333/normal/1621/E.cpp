//CF1621E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<18;
int n,m,mx=100005,a[N],b[N];
LL c[N];
vector<int> v[N];
int di(LL x,int y){
	return (x+y-1)/y;
}
int t[N],w[N];
void ch(int k,int x){
	t[k]+=x;
	w[k]+=x;
}
void modify(int L,int R,int X,int k=1,int l=1,int r=mx){
	if(L<=l&&r<=R){
		ch(k,X);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
	t[k]=min(t[k<<1],t[k<<1|1])+w[k];
}
int main()
{
	int T,i,j,x;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(t,0,sizeof(t));
		memset(w,0,sizeof(w));
		for(i=1;i<=n;i++)
			scanf("%d",a+i),modify(1,a[i],1);
		for(i=1;i<=m;i++){
			scanf("%d",b+i);
			c[i]=0;
			for(j=0;j<b[i];j++){
				scanf("%d",&x);
				v[i].push_back(x);
				c[i]+=x;
			}
			modify(1,di(c[i],b[i]),-1);
		}
		for(i=1;i<=m;i++){
			modify(1,di(c[i],b[i]),1);
			for(j=0;j<b[i];j++){
				x=v[i][j];
				if(b[i]>1)
					modify(1,di(c[i]-x,b[i]-1),-1);
				if(t[1]>=0)
					printf("1");
				else
					printf("0");
				if(b[i]>1)
					modify(1,di(c[i]-x,b[i]-1),1);
			}
			modify(1,di(c[i],b[i]),-1);
		}
		printf("\n");
		for(i=1;i<=m;i++)
			v[i].clear();
	}
	return 0;
}