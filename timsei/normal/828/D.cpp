using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define F(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define ll long long
#define N 400005
int ne[N],to[N],fir[N],cnt;
int dis[N];
int now[N];
int n,k,m;
int from[N];
void add(int x,int y){
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;from[cnt]=x;
}
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	scanf("%d%d",&n,&k);
	m=n-k;
	m--;
	if(!k) {
		printf("%d\n",(n)/2);
		for(int i=1;i<=n;i++) {
			printf("%d %d\n",i,(i)%n+1);
		}
		return 0;
	}
	if(k==1) {
		if(n==1) {
			puts("0");return 0;
		}
		printf("%d\n",(n)/2+1);
		for(int i=1;i<=n-1;i++) {
			printf("%d %d\n",i,i%(n-1)+1);
		}
		return 0;
	}
	for(int i=2;i<=k+1;i++) {
		add(1,i);dis[i]=1;now[i]=i;
	}
	for(int j=k+2;j<=m+k+1;j++) {
		int hh=(j%(k))+2;
		add(now[hh],j);dis[hh]++;now[hh]=j;
	}
	sort(dis+1,dis+k+5,cmp);
	int ans=dis[1]+dis[2];
	cout<<ans<<endl;
	for(int i=1;i<=cnt;i++) {
		printf("%d %d\n",from[i],to[i]);
	}
}