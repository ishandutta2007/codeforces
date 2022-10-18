#include<bits/stdc++.h>

int f[10];
inline int qry(int k){
	f[k]=0;
	printf("? %d\n",200/(1<<k)*200);
	for(int i=1;i<=200;i++)
		if(i%(1<<k)==0)
			for(int j=1;j<=200;j++)
				printf("%d %d ",i,j);
	puts("");
	fflush(stdout);
	scanf("%d",&f[k]);
	return f[k];
}

int main(){
	int s=qry(0);
	int L=1,R=7,res=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if((qry(mid)<<mid)==s){
			res=mid;
			L=mid+1;
		}
		else
			R=mid-1;
	}
	int l=std::abs((f[res+1]<<(res+1))-s)>>res;
	printf("! %d\n",2*(l+s/l)-4);
}