#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,nex;
};
edge ed[10005];
int cnt,h[1005],deep[1005];
void add(int st,int et){
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nex=h[st];
	h[st]=cnt;
}
long double pai=acos(-1);
struct node{
	long double x,y,r;
}a[1005];
bool cmp(node q1,node q2){
	return q1.r>q2.r;
}
int n;
void dfs(int x){
	for(int i=h[x];i;i=ed[i].nex){
		int v=ed[i].to;
		deep[v]=deep[x]+1;
		dfs(v);
	}
}
int main(){
	scanf("%d",&n);
	a[0].r=1e7+5;
	a[0].x=0;
	a[0].y=0;
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf%Lf",&a[i].x,&a[i].y,&a[i].r);
	}
	sort(a,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int o=i-1;o>=0;o--){
			if((a[i].x-a[o].x)*(a[i].x-a[o].x)+(a[i].y-a[o].y)*(a[i].y-a[o].y)<a[o].r*a[o].r){
				add(o,i);
				break;
			}
		}
	}
	dfs(0);
	long double ans=0;
	for(int i=1;i<=n;i++){
		if(deep[i]==1||deep[i]==2){
			ans+=a[i].r*a[i].r*pai;
		}
		else{
			ans+=deep[i]%2==1?-a[i].r*a[i].r*pai:a[i].r*a[i].r*pai;
		}
	}
	printf("%.9Lf",ans);
	return 0;
}