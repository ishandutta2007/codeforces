#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define D(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
typedef long long ll;
const int N=1000005;
int n,lu,rd,nu,nd;char g[N];
ll gl,gr,ans[N],sd[N],su[N];
int main(){
	scanf("%d\n%s",&n,g+1);
	F(i,1,n)if(g[i]=='D')nd++,sd[nd]=sd[nd-1]+i;
	F(i,1,n)if(g[i]=='U')nu++,su[nu]=su[nu-1]+i;
	rd=nd-(g[1]=='D');
	F(i,1,n){
		if(g[i]=='U'){
			if (rd>lu){ // 
				ans[i] = 2*(sd[nd-rd+lu+1]-sd[nd-rd]);
				ans[i] -= i; ans[i] -= 2*su[lu];
			} else { // 
				ans[i] = 2*(sd[nd]-sd[nd-rd]);
				ans[i] += n+1-i; ans[i] -= 2*(su[lu]-su[lu-rd]);
			}
		} else {
			if (rd>=lu){ // 
				ans[i] = 2*(sd[nd-rd+lu]-sd[nd-rd]);
				ans[i] += i; ans[i] -= 2*su[lu];
			} else { // 
				ans[i] = 2*(sd[nd]-sd[nd-rd]);
				ans[i] += n+1+i; ans[i] -= 2*(su[lu]-su[lu-rd-1]);
			}
		}
		printf("%I64d ",ans[i]);
		if(g[i]=='U') lu++;
		if(g[i+1]=='D') rd--;
	}
	return 0;
}