#include<bits/stdc++.h>

using namespace std;

const int N=300005;
int n,a[N],b[N];
int dis[N],q[N],fa[N];
int fr1[N],fr2[N];

int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void Output(int x){
	*q=0;
	q[++*q]=0;
	for (;x!=n;){
		q[++*q]=fr1[x];
		x=fr2[x];
	}
	printf("%d\n",*q);
	for (int i=*q;i>=1;i--)
		printf("%d ",q[i]);
	exit(0);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=0;i<=n;i++)
		dis[i]=1<<30,fa[i]=i;
	int h=0,t=1;
	dis[n]=0; q[1]=n;
	while (h!=t){
		int x=q[++h];
		for (int j=get(x-1);j>=x-a[x];j=get(j)){
			if (j==0) Output(x);
			fa[j]=j-1;
			if (dis[j+b[j]]>dis[x]+1){
				fr1[j+b[j]]=j;
				fr2[j+b[j]]=x;
				dis[j+b[j]]=dis[x]+1;
				q[++t]=j+b[j];
			}
		}
	}
	puts("-1");
}