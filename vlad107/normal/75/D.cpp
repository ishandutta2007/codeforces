#include <stdio.h>
#include <algorithm>

#define INF 1000000000000000000LL

int n,m,kg;
long long sum[500500],mpr[500500],msf[500500],tr[500500],res=-INF;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d",&kg);
		sum[i]=0;mpr[i]=0;
		msf[i]=0;tr[i]=-INF;
		for (int j=0;j<kg;j++){
			int x;
			scanf("%d",&x);
			sum[i]+=x;
			if (sum[i]>msf[i])msf[i]=sum[i];
			mpr[i]+=x;
			if (mpr[i]>tr[i])tr[i]=mpr[i];
			if (j!=kg-1&&mpr[i]<0)mpr[i]=0;
		}
	}
	long long ss=0;
	for (int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		x--;
		if (i==0){
			res=tr[x];
			ss=mpr[x];
			continue;
		}
		if (tr[x]>res)res=tr[x];
		if (msf[x]+ss>res)res=msf[x]+ss;
		ss+=sum[x];
		if (mpr[x]>ss)ss=mpr[x];
		if (ss>res)res=ss;
	}
	printf("%I64d\n",res);
}