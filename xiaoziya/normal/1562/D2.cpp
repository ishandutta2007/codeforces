#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
const int maxn=300005;
int T,n,q;
int sum[maxn];
set<int>st[maxn<<2];
string s;
int solve(int l,int r){
	int val=sum[l-1]+sum[r];
	return *st[2*n+val].lower_bound(l);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q),cin>>s,s=" "+s;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(s[i]=='+'? 1:-1)*(i%2==0? -1:1);
			st[2*n+sum[i]+sum[i-1]].insert(i);
		}
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(sum[r]-sum[l-1]==0){ 
				puts("0");
				continue;
			}
			if((r-l+1)&1){
				puts("1");
				printf("%d\n",solve(l,r));
			}
			else{
				puts("2");
				printf("%d %d\n",solve(l,r-1),r);
			}
		}
		for(int i=1;i<=n;i++)
			st[2*n+sum[i]+sum[i-1]].clear();
	}
	return 0;
}