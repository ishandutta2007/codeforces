#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=1005;
int n,a[N],ansl[N],ansr[N];
bool ok(){
	rep(i,1,n)if(a[i]!=i)return 0;
	return 1;
}
void solve(int step){
	if(ok()){
		printf("%d\n",step);
		for(int i=step-1;i>=0;--i)printf("%d %d\n",ansl[i],ansr[i]);
		std::exit(0);
	}
	if(step==3)return;
	std::vector<int>tmp;
	rep(i,1,n)if(i==1||i==n||abs(a[i]-a[i-1])!=1||abs(a[i]-a[i+1])!=1)tmp.push_back(i);
	for(int i:tmp)for(int j:tmp)if(i<j){
//		fprintf(stderr,"%d %d %d\n",step,i,j);
		std::reverse(a+i,a+1+j);
		ansl[step]=i,ansr[step]=j;
		solve(step+1);
		std::reverse(a+i,a+1+j);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	solve(0);
	return 0;
}