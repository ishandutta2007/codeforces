#include<bits/stdc++.h>

inline int qry(int x){
	static int res;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}

int n;

int main(){
	scanf("%d",&n);
	int L=n+n-1,R=n*2000+n-1,res=R;
	while(L<=R){
		int mid=(L+R)>>1;
		if(qry(mid)==1)
			res=mid,R=mid-1;
		else
			L=mid+1;
	}
	int ans=res;
	for(int i=2;i<=n;i++){
		int x=(res-1)/i,y=qry(x);
		if(y)
			ans=std::min(ans,y*x);
	}
	printf("! %d\n",ans);
}