/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int T,n,K,p[1001000],L[1001000],R[1001000],res;
void mina(){
	scanf("%d%d",&n,&K),res=1;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=K;i++)L[i]=0,R[i]=i-1;
	for(int i=1;i<=n;i++){
		if(i+K>n){
			if(p[i]>0){puts("0");return;}
			continue;
		}
		if(p[i]==-1)L[i+K]=0,R[i+K]=i+K-1;
		else if(!p[i])L[i+K]=0,R[i+K]=K;
		else L[i+K]=R[i+K]=p[i]+K;
	}
	for(int i=1;i<=n;i++)res=1ll*res*(R[i]-L[i]+1)%mod;
	printf("%d\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}