#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int p[110000],len,pd[110000],n,m,u[110000],where;
int father[110000],w[110000];
int getfather(int k1){
	if (father[k1]==k1) return k1;
	int pre=getfather(father[k1]);
	w[k1]^=w[father[k1]]; father[k1]=pre; return pre;
}
int add(int k1,int k2,int ww){
//	cout<<"add "<<k1<<" "<<k2<<" "<<ww<<endl;
	int k3=getfather(k1),k4=getfather(k2);
	if (k3==k4) return (w[k1]^w[k2])==ww;
	father[k3]=k4; w[k3]=(w[k1]^w[k2]^ww);
	return 1;
}
int main(){
	scanf("%d%d",&m,&n);
	memset(p,0xff,sizeof p); len=-1;
	for (int i=0;i<m;i++) scanf("%d",&pd[i]),pd[i]^=1;
	for (int i=1;i<=n;i++) father[i]=i,w[i]=0;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		for (;k1;k1--){
			int k2; scanf("%d",&k2);
			if (u[k2]==0) u[k2]=i; else{
				if (add(u[k2],i,pd[k2-1])==0){
					printf("NO\n"); return 0;
				}
			}
		}
	}
	printf("YES\n"); return 0;
}