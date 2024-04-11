#include<stdio.h>
#include<string.h>
using namespace std;
char a[200010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		int l=0,r=0,u=0,d=0,len=strlen(a),x=0,y=0;
		int fl=0,fr=0,fu=0,fd=0;
		for(int i=0;i<len;i++){
			if(a[i]=='W'){
				if(++y>u)u=y,fd=0,fu=1;
				else if(y==u)fu=1;
			}
			if(a[i]=='A'){
				if(--x<l)l=x,fr=0,fl=1;
				else if(x==l)fl=1;
			}
			if(a[i]=='S'){
				if(--y<d)d=y,fu=0,fd=1;
				else if(y==d)fd=1;
			}
			if(a[i]=='D'){
				if(++x>r)r=x,fl=0,fr=1;
				else if(x==r)fr=1;
			}	
		}
		x=r-l+1,y=u-d+1;
		long long s=1LL*x*y,k=s;
		if(x>2&&fl*fr==0)s=k-y;
		if(y>2&&fu*fd==0)if(k-x<s)s=k-x;
		printf("%I64d\n",s);
	}
}