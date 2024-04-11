#include<bits/stdc++.h> 
using namespace std;
const int N=1000005;
int T,n,a[N],used[N],q[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),used[i]=0;
		int k1=1;
		while(!used[k1]){
			used[k1]=1;
			k1=k1-a[k1];
		}
		q[0]=0;
		int k2=k1;
		do{
			q[++*q]=k2;
			k2=k2-a[k2];
		}while(k2!=k1);
		printf("%d\n",*q);
		for(int i=1;i<=*q;++i)printf("%d ",q[i]);puts("");
	}
	return 0;
}