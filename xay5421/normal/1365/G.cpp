#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef vector<int>VI;
typedef long long LL;
const int N=1005;
int n,num[N];LL a[N];
int main(){
	scanf("%d",&n);
	int j=0;
	rep(i,1,n){
		while(__builtin_popcount(j)!=6)++j;
		num[i]=j++;
	}
	rep(i,0,12){
		VI A;
		rep(j,1,n)if(num[j]>>i&1)A.PB(j);
		if(A.empty())continue;
		printf("? ");
		printf("%d ",SZ(A));
		for(auto x:A)printf("%d ",x);puts("");
		fflush(stdout);
		scanf("%lld",&a[i]);
	}
	printf("! ");
	rep(i,1,n){
		LL res=0;
		rep(j,0,12)if(~num[i]>>j&1){
			res|=a[j];
		}
		printf("%lld ",res);
	}
	puts("");
	fflush(stdout);
}