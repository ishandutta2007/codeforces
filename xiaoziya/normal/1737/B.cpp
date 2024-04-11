#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
long long calc(long long n){
	long long v=(long long)sqrt(n);
	long long res=3*(v-1)+1;
	if(v*v+v<=n)
		res++;
	if(v*v+v+v<=n)
		res++;
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		long long A,B;
		scanf("%lld%lld",&A,&B);
		printf("%lld\n",calc(B)-calc(A-1));
	}
	return 0;
}