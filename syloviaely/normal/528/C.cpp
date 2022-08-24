#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point;
}b[800010];
int p[110000],len,n,m,A[110000],pd[810000],w[110000],ans[810000][2],in[110000],out[110000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void findans(int k){
	for (;p[k]!=-1;){
		int j=b[p[k]].point,i=p[k]; p[k]=b[p[k]].next;
		if (pd[i>>1]) continue;
		pd[i>>1]=1; findans(j);
		len++; ans[len][0]=k; ans[len][1]=j;
	}
}
int main(){
	scanf("%d%d",&n,&m); len=-1;
	memset(p,0xff,sizeof p);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2); w[k1]++; w[k2]++;
	}
	int now=0;
	for (int i=1;i<=n;i++)
		if (w[i]%2) A[++now]=i;
	for (int i=1;i<=now;i+=2){
		m++; add(A[i],A[i+1]);
	}
	if (m%2){
		m++; add(1,1);
	}
	len=0;
	findans(1);
	for (int i=1;i<=len;i++) {in[ans[i][1]]++; out[ans[i][0]]++;}
	printf("%d\n",len);
	for (int i=1;i<=len;i++) if (i%2)printf("%d %d\n",ans[i][0],ans[i][1]); else printf("%d %d\n",ans[i][1],ans[i][0]); 
}