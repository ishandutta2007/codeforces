#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int T,n,a[N],b[N];

void work(int x){
	for(int i=1;i<=x/2;i++) swap(a[i],a[x-i+1]);
	return ;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]%2!=i%2){
				flag=0;
				break;
			}
		}
		if(!flag) printf("-1\n");
		else{
			int m=0;
			for(int i=n;i>1;i-=2){
				int j=0,k=0;
				for(int p=1;p<=n;p++) if(a[p]==i) j=p;
				if(j!=1){
					b[++m]=j;work(j);
				}
				for(int p=1;p<=n;p++) if(a[p]==i-1) j=p;
				if(j!=2){
					b[++m]=j-1;work(j-1);
				}
				b[++m]=j+1;work(j+1);
				b[++m]=3;work(3);
				b[++m]=i;work(i);
			}
			printf("%d\n",m);
			for(int i=1;i<=m;i++) printf("%d ",b[i]);		
		}
	}
	return 0;
}