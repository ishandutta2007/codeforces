#include<stdio.h>
#include<math.h>
#define int long long
int T,n;
inline int query(int l,int r){
	if(l>=r)
		return 0;
	int x;
	printf("? %lld %lld\n",l,r),fflush(stdout),scanf("%lld",&x);
	return x;
}
int calc(int x){
	return sqrt(x+x)+1;
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		int all=query(1,n),S=sqrt(2*all)+1;		
		int L=0,R=n+1,lst=0;
		while(L+1<R){
			int mid=(L+R)>>1;
			if(query(1,mid))
				R=mid;
			else L=mid;
		}
		if(query(1,R)==all)
			R--;
		int pos=R,x=query(1,pos),y=query(1,pos+1),mid;
		if(x==y)
			mid=pos+1;
		else{
			int left=pos-(y-x-1);
			int t=query(1,left-1);
			if(t==0){
				int right=left+S-1;
				mid=right-(query(1,right+1)-query(1,right)-1);
			}
			else mid=left;
		}
		int q=query(1,mid-1),qq=calc(q),v=all-q,vv=calc(v);
		printf("! %lld %lld %lld\n",mid-1-qq+1,mid,mid+vv-1),fflush(stdout);
	}
	return 0;
}