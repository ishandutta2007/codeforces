#include<cstdio>
#define ull unsigned long long

int n,a,d;

int main(){
	scanf("%d%d%d",&n,&a,&d);
	printf("%llu %llu\n",368131125ull*a%(ull)(1e9)*12ull*(ull)(1e9)+1,368131125ull*d%(ull)(1e9)*12ull*(ull)(1e9));
}