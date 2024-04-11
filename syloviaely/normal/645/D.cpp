#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
struct bian{
	int next,point;
}b[110000];
int p[110000],len,d[110000],n,m,x[110000],pd[110000],u[110000],v[110000],ne[110000];
queue<int>Q;
void add(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len; d[k2]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
		u[i]=k1; v[i]=k2;
	}
	len=0;
	for (int i=1;i<=n;i++) if (d[i]==0) Q.push(i),d[i]=-1;
	while (!Q.empty()){
		int k=Q.front();
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			d[j]--;
			if (d[j]==0){
				d[j]=-1; Q.push(j);
			}
		}
		x[++len]=k; Q.pop();
	}
	for (int i=1;i<n;i++) ne[x[i]]=x[i+1];
	memset(pd,0x00,sizeof pd);
	int rem=n-1;
	for (int i=1;i<=m;i++)
		if (v[i]==ne[u[i]]){
			rem--; if (rem==0){cout<<i<<endl; return 0;}
		}
	cout<<-1<<endl; return 0;
}