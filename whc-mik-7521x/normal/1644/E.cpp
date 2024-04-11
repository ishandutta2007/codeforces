#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,nux,nuy,x,y,xx,yy;
long long s1,s2;
char s[N];
int main(){
    long long t;
	scanf("%lld",&t);
	while(t--){
        nux=-1,nuy=-1;
        x=1,y=1,xx=1,yy=1;
		scanf("%lld%s",&n,s+1);
        long long m=strlen(s+1);
		long long mx,my;
		long long ans=0;
		for(long long i=1;i<=m;i++){
            if(s[i]=='D')x++;
            if(s[i]=='R')y++;
			if(x==2&&nux==-1)nux=i,my=y;
			if(y==2&&nuy==-1)nuy=i,mx=x;
		}
		if(nux==-1||nuy==-1){printf("%lld\n",n);continue;}
        s1=0,s2=0;
		if(nux>nuy){
			for(long long i=1;i<=m;i++){
                if(s[i]=='D')xx++;
                if(s[i]=='R')yy++;
				if(s[i]=='D'&&yy>my)s1+=yy-my;
				if(s[i]=='R')s2+=xx-1;
			}
			printf("%lld\n",(n-my+1)*n-s1-s2+my-1);
		}
		else{
			for(long long i=1;i<=m;i++){
                if(s[i]=='D')xx++;
                if(s[i]=='R')yy++;
				if(s[i]=='D')s1+=yy-1;
				if(s[i]=='R'&&xx>mx)s2+=xx-mx;
			}
			printf("%lld\n",(n-mx+1)*n-s1-s2+mx-1);
		}
	}
	return 0;
}