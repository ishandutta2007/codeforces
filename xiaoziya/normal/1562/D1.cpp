#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=300005;
int T,n,q;
int sum[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q),cin>>s,s=" "+s;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(s[i]=='+'? 1:-1)*(i%2==0? -1:1);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(sum[r]-sum[l-1]==0){ 
				puts("0");
				continue;
			}
			if((r-l+1)&1)
				puts("1");
			else puts("2");
		}
	}
	return 0;
}