#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main() {
	int n,s0=0,s1=(1<<10)-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		char ch;
		int val;
		scanf(" %c %d",&ch,&val);
		if(ch=='|') {
			s0|=val, s1|=val;
		}
		else if(ch=='&') {
			s0&=val, s1&=val;
		}
		else {
			s0^=val, s1^=val;
		}
	}	
	int av=0,ov=0,xv=0,flag=1;
	for(int i=0;i<10;i++) {
		int t1=s0&1,t2=s1&1;
		if(t1==t2) {
			if(t1==1) ov|=(1<<i);
		}
		else {
			if(t2==1) av|=(1<<i);
			else {
				av|=(1<<i);
				xv|=(1<<i),flag=0;
			}
		}
		s0>>=1; s1>>=1;
	}
	printf("%d\n",3-flag);
	printf("& %d\n| %d\n",av,ov);
	if(!flag)printf("^ %d\n",xv);
	return 0;
}