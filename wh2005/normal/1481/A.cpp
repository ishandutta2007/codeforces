#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T;
char s[N];


int main(){
	scanf("%d",&T);
	while(T--){
		int u=0,d=0,l=0,r=0,x=0,y=0;
		int a,b;scanf("%d%d",&a,&b);	
		scanf("%s",s);int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='U') u++,y++;
			if(s[i]=='D') d++,y--;
			if(s[i]=='L') l++,x--;
			if(s[i]=='R') r++,x++; 
		}		
		a-=x,b-=y;int flag=1;
		if(b>0&&d<b) flag=0;
		if(b<0&&u<-b) flag=0;
		if(a>0&&l<a) flag=0;
		if(a<0&&r<-a) flag=0;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}