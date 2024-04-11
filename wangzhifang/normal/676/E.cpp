#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define max_n 100000
using namespace std;
int n,k;
const int mod[]={10007,1000007,1000000007,19260817,999911659};
int a[max_n+1];
bool ok[max_n+1];
char s[20];
int main(){
    scanf("%d%d",&n,&k);
    int cnt=0;
    memset(ok,0,sizeof(ok));
    for(int i=-1,t,tmp; ++i<=n; ){
        scanf("%s",s);
        if(s[0]=='?')
        	++cnt,ok[i]=1;
        else{
            t=s[0]=='-'?-1:1,tmp=0;
			for(char*j=s+(s[0]=='-')-1; *++j; tmp=tmp*10+(*j^'0'));
            a[i]=tmp*t;
		}
	}
    if(!k)
    	puts((ok[0]?((n+1-cnt)&1):int(!a[0]))?"Yes":"No");
    else
    	if(cnt)
    		puts((n&1)?"Yes":"No");
		else{
			long long tmp=0;
			for(int j=-1; ++j<5; ){
				for(int i=n+1; ~--i; tmp=(tmp*k+a[i])%mod[j]);
				if(tmp){
					puts("No");
					return 0;
				}
			}
			puts("Yes");
		}
    return 0;
}