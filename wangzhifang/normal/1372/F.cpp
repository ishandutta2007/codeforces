#include <cstdio>
using namespace std;
#define max_n 200000
int a[max_n+1];
void solve(const int&l,const int&r){
	if(l>r)	
		return ;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x,f;
	scanf("%d%d",&x,&f);
	int ll=r-f+1,rr=l+f-1;
	if(ll<=rr){
		for(int i=ll; i<=rr; ++i)
			a[i]=x;
		solve(l,ll-1),solve(rr+1,r);
	}
	else{
		int i=l;
		for(solve(l,rr); (rr+=f)<r; solve(i+=f,rr));
		solve(i+f,r);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	solve(1,n);
	printf("!");
	for(int i=1; i<=n; ++i)
		printf(" %d",a[i]);
	putchar('\n');
	return 0;
}