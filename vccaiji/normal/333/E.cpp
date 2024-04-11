#include<bits/stdc++.h>
using namespace std;
int x[3100],y[3100];
inline int d(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
struct edge{
	int i,j,d;
}e[9100000];
bool cmp(edge a,edge b){
	return a.d>b.d;
}
bitset<3005> c[3005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	int tot=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		e[++tot].i=i;
		e[tot].j=j;
		e[tot].d=d(i,j);
	}
	sort(e+1,e+tot+1,cmp);
	int ans=0;
	for(int i=1;i<=tot;i++){
		c[e[i].i][e[i].j]=1;
		c[e[i].j][e[i].i]=1;
		if((c[e[i].i]&c[e[i].j]).count()!=0){
			ans=e[i].d;
			break;
		}
	}
	printf("%.8lf",sqrt((double)ans)/2);
	return 0;
}