//lol E
#include <bits/stdc++.h>
#define MOD 998244353
 
using namespace std;
 
typedef long long ll;
 
inline void add(int &x,int y) {
  ((x+=y)>=MOD)?x-=MOD:0;
}
 
int f[2][21][21][21][21][4]; 
int ux[1<<5],dx[1<<5],uy[1<<5],dy[1<<5];
 
int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	for(int j=0;j<(1<<n);j++)
  	  if ((j>>(i-1))&1) {
  	  	  if (x>0) ux[j]+=x; else dx[j]+=-x;
		  if (y>0) uy[j]+=y; else dy[j]+=-y; 
		}
  }
  int cur=0,up=(n<<2);
  f[cur][0][0][0][0][0]=1;
  for(int i=0;i<=30;i++) {
  	bool v=((m>>i)&1);
  	cur^=1;
  	memset(f[cur],0,sizeof(f[cur]));
  	for(int t1=0;t1<=up;t1++)
  	for(int t2=0;t2<=up;t2++)
  	for(int t3=0;t3<=up;t3++)
  	for(int t4=0;t4<=up;t4++)
  	for(int t5=0;t5<4;t5++)
  	  if (f[cur^1][t1][t2][t3][t4][t5]) {
  	  	  int t=f[cur^1][t1][t2][t3][t4][t5];
  	  	  for(int j=0;j<(1<<n);j++) {
  	  	  	    if ((((t1+ux[j])^(t2+dx[j]))&1)||(((t3+uy[j])^(t4+dy[j]))&1)) continue;
  	  	  	    int v1=t1+ux[j],v2=t2+dx[j],v3=t3+uy[j],v4=t4+dy[j];
  	  	  	    if (!v) 
  	  	  	        add(f[cur][v1>>1][v2>>1][v3>>1][v4>>1][t5|(v1&1)|((v3&1)<<1)],t);
				else 
				    add(f[cur][v1>>1][v2>>1][v3>>1][v4>>1][t5&((v1&1)^((v3&1)<<1))],t);
			  }
		}
  }
  printf("%d\n",(f[cur][0][0][0][0][0]-1+MOD)%MOD);
  return 0;
}