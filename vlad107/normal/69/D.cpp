#include <stdio.h>
#include <memory.h>

int vx[22],vy[22],x,y,n,d,f[700][700][2][2][2];

bool rec(int x,int y,int q1,int q2,int o){
	if (f[x+200][y+200][q1][q2][o]>=0)return f[x+200][y+200][q1][q2][o];
	if (x*x+y*y>d*d){f[x+200][y+200][q1][q2][o]=1;return true;}
	if (o==0&&q1==0&&!rec(y,x,1,q2,1)){f[x+200][y+200][q1][q2][o]=1;return true;}
	if (o==1&&q2==0&&!rec(y,x,q1,1,0)){f[x+200][y+200][q1][q2][o]=1;return true;}
	for (int i=0;i<n;i++)
		if (!rec(x+vx[i],y+vy[i],q1,q2,1-o)){f[x+200][y+200][q1][q2][o]=1;return true;}
	f[x+200][y+200][q1][q2][o]=0;
	return false;
}

int main(){
	scanf("%d%d%d%d",&x,&y,&n,&d);
	for (int i=0;i<n;i++)scanf("%d%d",&vx[i],&vy[i]);
	memset(f,-1,sizeof(f));
	if (rec(x,y,0,0,0))
		puts("Anton");
	else puts("Dasha");
}