#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=1000005;
int n;
int pre[maxn][2];
string s;
int main(){
	scanf("%d",&n),cin>>s,s=" "+s;
	for(int i=1;i<=n;i++){
		pre[i][0]=pre[i-1][0],pre[i][1]=pre[i-1][1];
		if(s[i]=='0')
			pre[i][1]=i;
		if(s[i]=='1')
			pre[i][0]=i;
	}
	for(int i=1;i<=n;i++){
		int res=0,now=1;
		while(now+i-1<=n){
			if(pre[now+i-1][0]<now||pre[now+i-1][1]<now)
				res++,now+=i;
			else now=min(pre[now+i-1][0],pre[now+i-1][1])+1;
		}
		printf("%d%c",res,i==n? '\n':' ');
	}
	return 0;
}