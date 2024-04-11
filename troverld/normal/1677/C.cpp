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
typedef long long ll;
int T,p[100100],q[100100],r[100100],m,n;
bool vis[100100];
ll res;
void mina(){
	scanf("%d",&n),m=n,res=0;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)r[p[i]]=q[i],vis[i]=false;
	for(int i=1;i<=n;i++)if(!vis[i]){
		int k=0;
		for(int j=i;!vis[j];j=r[j])vis[j]=true,k++;
		if(k&1)m--;
	}
	for(int i=1;i<=(m>>1);i++)res+=((n-i+1)-i)<<1;
	printf("%lld\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}