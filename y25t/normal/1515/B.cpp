#include<cstdio>
#include<cmath>
#include<algorithm>

int T;

int n;

inline int chk(int x){
	int k=std::floor(std::sqrt((double)x));
	if(k*k==x)
		return 1;
	k++;
	if(k*k==x)
		return 1;
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		puts((n%2==0&&chk(n/2))||(n%4==0&&chk(n/4))?"YES":"NO");
	}
}