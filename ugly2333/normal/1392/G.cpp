//CF1392G
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
const int N = 1<<20;
const int K = 22;
int n,m,k,q,a[N],b[N],p[K],d[N],f[N];
char s[K],t[K];
queue<int> Q;
void bfs(int x){
	int i;
	d[x]=0;
	Q.push(x);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=1;i<q;i<<=1)
			if(d[x^i]>d[x]+1)
				d[x^i]=d[x]+1,f[x^i]=f[x],Q.push(x^i);
	}
}
void cal(int i){
	int j;
	a[i]=0,b[i]=0;
	for(j=0;j<k;j=j+1)
		if(s[j]=='1')
			a[i]|=1<<p[j];
	for(j=0;j<k;j=j+1)
		if(t[j]=='1')
			b[i]|=1<<p[j];
}
int main()
{
	int i,ans,ansl,ansr;
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	for(i=0;i<k;i=i+1)
		p[i]=i;
	cal(0);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,b+i);
		a[i]--,b[i]--;
		swap(p[a[i]],p[b[i]]);
		cal(i);
	}
	q=1<<k;
	for(i=0;i<q;i=i+1)
		d[i]=N;
	ans=N;
	for(i=n;i>=m;i=i-1){
		f[b[i]]=i;
		bfs(b[i]);
		if(ans>d[a[i-m]])
			ans=d[a[i-m]],ansl=i-m+1,ansr=f[a[i-m]];
	}
	printf("%d\n%d %d",k-ans,ansl,ansr);
	return 0;
}