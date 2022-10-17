#include<stdio.h>
#include<iostream>
using namespace std;
int T,n;
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cin>>s,s=" "+s;
		int pos=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				pos=i;
				break;
			}
		if(pos==0){
			printf("%d %d %d %d\n",1,n/2,(n+3)/2,n);
			continue;
		}
		if(n-(pos+1)+1>=n/2)
			printf("%d %d %d %d\n",pos,n,pos+1,n);
		else printf("%d %d %d %d\n",1,pos,1,pos-1);
	}
	return 0;
}