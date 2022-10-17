#include<stdio.h>
#include<iostream>
#define int long long
using namespace std;
int T,k;
string s;
int check(int x){
	if(x<=1)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&k),cin>>s,s=" "+s;
		int flg=0;
		for(int i=1;i<=k;i++)
			if((s[i]%2==0&&s[i]>'2')||s[i]=='9'||s[i]=='1'){
				flg=i;
				break;
			}
		if(flg){
			printf("1\n%c\n",s[flg]);
			continue;
		}
		int p1=0,p2=0;
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++)
				if(s[i]==s[j]){
					p1=i,p2=j;
					break;
				}
		if(p1){
			printf("2\n%c%c\n",s[p1],s[p2]);
			continue;
		}
		int ans=k+1,pos=0;
		for(int i=1;i<(1<<k);i++){
			int val=0,tot=0;
			for(int j=1;j<=k;j++)
				if((i>>(j-1))&1)
					tot++,val=val*10+(s[j]-48);
			if(check(val)==0&&tot<ans)
				ans=tot,pos=i;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=k;i++)
			if((pos>>(i-1))&1)
				printf("%c",s[i]);
		puts("");
	}
	return 0;
}