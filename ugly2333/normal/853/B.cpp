//CF 853B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
const int K = 1111111;
struct node{
	int d;
	int r;
	int c;
}t[N],f[N];
bool cmp(node al,node bl){
	return al.d<bl.d;
}
LL T[K],F[K],ans;
int a[N];
int main()
{
	int n,m,k,w,x,y,z,i,j,st,sf,ss,pt,pf;
	st=0;
	sf=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d%d",&w,&x,&y,&z);
		if(y==0){
			st++;
			t[st].d=w;
			t[st].r=x;
			t[st].c=z;
		}
		else{
			sf++;
			f[sf].d=w;
			f[sf].r=y;
			f[sf].c=z;
		}
	}
	sort(t+1,t+st+1,cmp);
	sort(f+1,f+sf+1,cmp);
	
	memset(a,0,sizeof(a));
	T[0]=0;
	ss=n;
	pt=1e6+1;
	j=1;
	for(i=1;i<=1e6;i=i+1){
		T[i]=T[i-1];
		while(j<=st&&t[j].d==i){
			x=t[j].r;
			z=t[j].c;
			if(!a[x]){
				T[i]+=(LL)z;
				a[x]=z;
				ss--;
			}
			if(z<a[x]){
				T[i]-=(LL)a[x];
				T[i]+=(LL)z;
				a[x]=z;
			}
			j++;
		}
		if(pt==1e6+1&&!ss)
			pt=i;
	}
	
	memset(a,0,sizeof(a));
	F[(int)1e6+1]=0;
	ss=n;
	pf=0;
	j=sf;
	for(i=1e6;i>=1;i=i-1){
		F[i]=F[i+1];
		while(j>=1&&f[j].d==i){
			x=f[j].r;
			z=f[j].c;
			if(!a[x]){
				F[i]+=(LL)z;
				a[x]=z;
				ss--;
			}
			if(z<a[x]){
				F[i]-=(LL)a[x];
				F[i]+=(LL)z;
				a[x]=z;
			}
			j--;
		}
		if(!pf&&!ss)
			pf=i;
	}
	ans=(LL)1<<60;
	for(i=pt;i+k+1<=pf;i=i+1)
		ans=min(ans,T[i]+F[i+k+1]);
	if(ans==(LL)1<<60)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}
/*
1 1 1
10 0 1 10

*/