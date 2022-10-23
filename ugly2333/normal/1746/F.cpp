//CF1746F
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
#include<random>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 666666;
int n,q,m,a[N],qx[N],qy[N],qz[N],ans[N],t[N],b[N],c[N];
map<int,int> mp;
map<int,int>::iterator it;
void ad(int x,int y){
	while(x<=n){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	mt19937 rng(123);
	int i,o;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),mp[a[i]]=1;
	for(i=1;i<=q;i++){
		scanf("%d%d%d",&o,qx+i,qy+i);
		if(o==2)
			scanf("%d",qz+i);
		else
			qz[i]=0;
		if(o==1)
			mp[qy[i]]=1;
		if(o!=1&&o!=2)
			cout<<1/0;
		ans[i]=1;
	}
	m=0;
	for(it=mp.begin();it!=mp.end();it++)
		(*it).second=++m;
	for(i=1;i<=n;i++)
		a[i]=mp[a[i]],c[i]=a[i];
	for(i=1;i<=q;i++)
		if(!qz[i])
			qy[i]=mp[qy[i]];
	for(o=1;o<=120;o++){
		memset(t,0,sizeof(t));
		for(i=1;i<=n;i++)
			a[i]=c[i];
		for(i=1;i<=m;i++)
			b[i]=rng()%1000;
		for(i=1;i<=n;i++)
			ad(i,b[a[i]]);
		for(i=1;i<=q;i++){
			if(qz[i]){
				if(ans[i]&&qz[i]>1&&(qu(qy[i])-qu(qx[i]-1))%qz[i])
					ans[i]=0;
			}
			else{
				ad(qx[i],b[qy[i]]-b[a[qx[i]]]);
				a[qx[i]]=qy[i];
			}
		}
	}
	for(i=1;i<=q;i++)
		if(qz[i]){
			if(ans[i])
				printf("YES\n");
			else
				printf("NO\n");
		}
	return 0;
}