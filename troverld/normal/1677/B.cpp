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
int T,n,m;
char s[1001000];
int d[2001000];
bool occ[1001000];
void mina(){
	scanf("%d%d%s",&n,&m,s);
	for(int i=0;i<n*m;i++)d[i]=0;
	int all=0;
	for(int i=0,las=-0x3f3f3f3f;i<n*m;i++)if(s[i]=='1'){
		if(las+m<=i)d[i]++,d[i+m]--;
		else d[las+m]++,d[i+m]--;
		las=i;
	}
	for(int i=0;i<n*m;i++)d[i+1]+=d[i];
	for(int i=0;i<n*m;i++)d[i+m]+=d[i];
	for(int i=0;i<n*m;i++){
		if(s[i]=='1'&&!occ[i%m])occ[i%m]=true,all++;
		printf("%d ",d[i]+all);
	}puts("");
	for(int i=0;i<m;i++)occ[i]=false;
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
}