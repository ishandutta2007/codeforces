#include <cstdio>
#include <algorithm>
#include <cstring>
#define max_n 100000
#define max_m 100000
using namespace std;
char s[max_n+1],t[max_m+1];
int p[max_n+1],q[max_n+1],ls[max_n+1],lt[max_n+1];
int main(){
	int n,m,q_,a,b,c,d;
	scanf("%s\n%s\n%d",s+1,t+1,&q_);
	n=strlen(s+1),m=strlen(t+1),p[0]=q[0]=ls[0]=lt[0]=0;
	for(int i=1; i<=n; ++i)
		s[i]!='A'?(ls[i]=0,p[i]=p[i-1]+1):(ls[i]=ls[i-1]+1,p[i]=p[i-1]);
	for(int i=1; i<=m; ++i)
		t[i]!='A'?(lt[i]=0,q[i]=q[i-1]+1):(lt[i]=lt[i-1]+1,q[i]=q[i-1]);
	do{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int tmp=(q[d]-q[c-1])-(p[b]-p[a-1]),tmp2=min(b-a+1,ls[b])-min(d-c+1,lt[d]);
//		printf("%d %d %d\n",ls[b],lt[d],tmp2);
		printf("%d",int(tmp>=0&&!(tmp&1)&&tmp2>=0&&(tmp2%3==0||tmp>=2)&&((p[b]-p[a-1])||!tmp||tmp2>0)));
	}while(--q_);
	return 0;
}