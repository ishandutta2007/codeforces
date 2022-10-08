#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005,M=200010;
struct node{
	int p,t,id;
	friend bool operator<(const node&a,const node&b){return a.p<b.p;}
}a[N],b[N];
int n,h,w,m1,m2,ax[N],ay[N],g;
queue<int>q[2][M];

int main(){
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++){
		scanf("%d",&g);
		if(g==1)++m1,scanf("%d%d",&a[m1].p,&a[m1].t),a[m1].id=i;
		else++m2,scanf("%d%d",&b[m2].p,&b[m2].t),b[m2].id=i;
	}
	sort(a+1,a+m1+1),sort(b+1,b+m2+1);
	for(int i=m2;i>=1;i--){
		int tnow=b[i].p-b[i].t+N;
		q[0][tnow].push(b[i].id);
		q[1][tnow].push(b[i].p);
	}
	for(int i=1;i<=m1;i++){
		int tnow=a[i].p-a[i].t+N;
		q[0][tnow].push(a[i].id);
		int p=q[0][tnow].front();
		ax[p]=a[i].p,ay[p]=h;
		q[0][tnow].pop();
	}
	for(int i=1;i<M;i++){
		while(!q[0][i].empty()){
			int p=q[0][i].front();
			ax[p]=w,ay[p]=q[1][i].front();
			q[0][i].pop(),q[1][i].pop();
		}
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ax[i],ay[i]);
	return 0;
}