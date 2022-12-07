#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],b[N],id[N],q[N];
double c[N],re;
bool cmp(int x,int y){
	return c[x]>c[y];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=20;i++){
		for (int j=1;j<=200000;j++) c[j]=0,id[j]=j;
		for (int j=1;j<=n;j++) c[a[j]]+=1.0*min(i,b[j])/i;
		sort(id+1,id+200001,cmp);
		double sum=0;
		for (int j=1;j<=i;j++) sum+=c[id[j]];
		if (sum>re){
			re=sum;	*q=0;
			for (int j=1;j<=i;j++) q[++*q]=id[j];
		}
	}
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++)
		printf("%d ",q[i]);
}
/*
<=20:  sort
>=20: Rp = b[i]/c[i]
*/