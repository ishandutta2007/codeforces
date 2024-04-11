#include<stdio.h>
const int maxn=1005,maxk=405;
int n,zero,anss,p1,p2,p3;
int ans[maxn*maxk][2];
struct candy{
	int v,p;
}c[maxn];
inline void chk(candy &a,candy &b){
	candy tmp;
	if(a.v>b.v)
		tmp=a,a=b,b=tmp;
}
inline void move(candy &a,candy &b){
	anss++,ans[anss][0]=a.p,ans[anss][1]=b.p;
	b.v-=a.v,a.v<<=1;
}
void merge(candy a,candy b,candy c,candy &res1,candy &res2){
	chk(a,b),chk(a,c),chk(b,c);
	if(a.v==0){
		res1=b,res2=c;
		return ;
	}
	int k=b.v/a.v;
	while(k){
		if(k&1)
			move(a,b);
		else move(a,c);
		k>>=1;
	}
	merge(a,b,c,res1,res2);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i].v),c[i].p=i;
		zero+=c[i].v==0;
	}
	if(n-zero<2){
		puts("-1");
		return 0;
	}
	for(p1=1;p1<=n&&c[p1].v==0;p1++);
	for(p2=p1+1;p2<=n&&c[p2].v==0;p2++);
	for(p3=p2+1;p3<=n&&c[p3].v==0;p3++);
	while(p3<=n){
		candy tmp1,tmp2;
		merge(c[p1],c[p2],c[p3],tmp1,tmp2);
		c[p2]=tmp1,c[p3]=tmp2;
		p1=p2,p2=p3;
		for(p3++;p3<=n&&c[p3].v==0;p3++);
	}
	printf("%d\n",anss);
	for(int i=1;i<=anss;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}