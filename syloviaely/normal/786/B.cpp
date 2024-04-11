#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct bian{
	int next,point,w;
}b[10000000];
int p[1000000],num,n,m,s,pd[1000000],len;
long long d[1000000];
priority_queue<pair<long long,int> >Q;
void add(int k1,int k2,int k3){
//	cout<<"add "<<k1<<" "<<k2<<" "<<k3<<endl;
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void getma(int k1,int k2,int k3){
	num=max(num,k1);
	if (k2==k3) return; int mid=k2+k3>>1;
	getma(k1*2,k2,mid);
	getma(k1*2+1,mid+1,k3);
}
void buildtree(int k1,int k2,int k3){
	if (k2!=k3){
		add(k1,k1*2,0); add(k1,k1*2+1,0);
		add(k1*2+num,k1+num,0); add(k1*2+1+num,k1+num,0);
	}
	if (k2==k3){
		add(k1,k2+num+num,0);
		add(k2+num+num,k1+num,0);
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
}
void add1(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k6,k1,k7); return;
	}
	int mid=k2+k3>>1;
	add1(k1*2,k2,mid,k4,k5,k6,k7);
	add1(k1*2+1,mid+1,k3,k4,k5,k6,k7);
}
void add2(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1+num,k6,k7); return;
	}
	int mid=k2+k3>>1;
	add2(k1*2,k2,mid,k4,k5,k6,k7);
	add2(k1*2+1,mid+1,k3,k4,k5,k6,k7);
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	getma(1,1,n); buildtree(1,1,n);
	memset(d,0x3f,sizeof d);
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2,k3,k4; scanf("%d%d%d",&k2,&k3,&k4);
			add(k2+num+num,k3+num+num,k4);
		} else if (k1==2){
			int k2,k3,k4,k5; scanf("%d%d%d%d",&k4,&k2,&k3,&k5);
			add1(1,1,n,k2,k3,k4+num+num,k5);
		} else if (k1==3){
			int k2,k3,k4,k5; scanf("%d%d%d%d",&k4,&k2,&k3,&k5);
			add2(1,1,n,k2,k3,k4+num+num,k5);
		}
	}
	d[s+num+num]=0; Q.push(make_pair(0,s+num+num));
	while (!Q.empty()){
		int where=Q.top().second;
		long long dis=Q.top().first; Q.pop();
		if (dis!=-d[where]||pd[where]) continue;
	//	cout<<where<<" "<<dis<<endl;
		pd[where]=1;
		for (int i=p[where];i;i=b[i].next){
			int j=b[i].point;
			if (d[where]+b[i].w<d[j]){
				d[j]=d[where]+b[i].w;
				Q.push(make_pair(-d[j],j));
			}
		}
	}
	for (int i=1;i<=n;i++) if (d[i+num+num]>1e18) printf("-1 "); else printf("%I64d ",d[i+num+num]);
	printf("\n");
}