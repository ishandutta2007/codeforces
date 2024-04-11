#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
struct atom{
	int x,y,w;
}A[1100000],B[1100000];
struct bian{
	int next,point;
}b[3100000];
int n,m,x[1100000],y[1100000],cnt,ans,f[1100000],p[1100000],len,d[1100000],dis[1100000];
queue<int>Q;
int compare(atom k1,atom k2){
	return k1.w<k2.w;
}
int compare2(atom k1,atom k2){
	return k1.y<k2.y;
}
void add(int k1,int k2){
//	cout<<"add "<<k1<<" "<<k2<<endl;
	b[++len]=(bian){p[k1],k2}; p[k1]=len; d[k2]++;
}
int findfather(int k1){
	if (k1==f[k1]) return k1; f[k1]=findfather(f[k1]); return f[k1];
}
void link(atom k1,atom k2){
	int k3=k1.x*m-m+k1.y,k4=k2.x*m-m+k2.y;
	k3=findfather(k3); k4=findfather(k4); f[k3]=k4;
}
void link2(atom k1,atom k2){
	//cout<<"link "<<k1.x<<" "<<k1.y<<" "<<k2.x<<" "<<k2.y<<endl;
	int k3=k1.x*m-m+k1.y,k4=k2.x*m-m+k2.y;
	k3=findfather(k3); k4=findfather(k4); 
	swap(k3,k4);
	add(k3,k4);
}
int main(){
	scanf("%d%d",&n,&m); cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cnt++; A[cnt].x=i; A[cnt].y=j; scanf("%d",&A[cnt].w);
		}
	for (int i=1;i<=cnt;i++) B[i]=A[i],f[i]=i;
	for (int i=1;i<=n;i++){
		int l=i*m+1-m,r=i*m;
		sort(B+l,B+r+1,compare);
		for (int j=l+1;j<=r;j++) if (B[j].w==B[j-1].w) link(B[j],B[j-1]);
	}
	sort(B+1,B+cnt+1,compare2);
	for (int i=1;i<=m;i++){
		int l=i*(n)+1-n,r=i*n;
		sort(B+l,B+r+1,compare);
		for (int j=l+1;j<=r;j++) if (B[j].w==B[j-1].w) link(B[j],B[j-1]);
	}
	for (int i=1;i<=cnt;i++) B[i]=A[i];
	for (int i=1;i<=n;i++){
		int l=i*(m)+1-m,r=i*m;
		sort(B+l,B+r+1,compare);
		for (int j=l+1;j<=r;j++) if (B[j].w!=B[j-1].w) link2(B[j-1],B[j]);
	}
	sort(B+1,B+cnt+1,compare2);
	for (int i=1;i<=m;i++){
		int l=i*(n)+1-n,r=i*n; 
		sort(B+l,B+r+1,compare);
		for (int j=l+1;j<=r;j++) if (B[j].w!=B[j-1].w) link2(B[j-1],B[j]);
	}
	memset(dis,0x00,sizeof dis); int ans=1;
	for (int i=1;i<=cnt;i++) if (d[i]==0&&f[i]==i){
		ans=1; Q.push(i);
	}
	sort(A+1,A+cnt+1,compare);
	for (int i=1;i<=cnt;i++){
		int k1=(A[i].x-1)*m+A[i].y; k1=findfather(k1);
		if (dis[k1]) continue;
		for (int j=p[k1];j;j=b[j].next){
			int k=b[j].point;
			dis[k1]=max(dis[k],dis[k1]);
		}
		dis[k1]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int k1=(i-1)*m+j; k1=findfather(k1); printf("%d ",dis[k1]);
		}
		printf("\n");
	}
	return 0;
}