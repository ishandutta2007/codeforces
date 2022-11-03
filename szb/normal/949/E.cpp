#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y)  for(int i=x;i<y;++i)
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
int n,gg[21][2000100],ans=100,up[100],down[100],qq[100],qwq[100],q1[100];
void ddddfs(int SHENDU,int ned){
	if (ned>=ans)return;
	if (SHENDU>19){if (ned<ans){ans=ned;For(i,0,20)qwq[i]=qq[i];}return;}
	bool frog=0;
	int up=1048576*2>>(SHENDU+1),down=0;
	For(i,down,up)if (gg[SHENDU-1][i<<1|1])frog=1;
	if (!frog){
		For(i,down,up) gg[SHENDU][i]=gg[SHENDU-1][i*2];
		qq[SHENDU]=0;
		ddddfs(SHENDU+1,ned);
		return;
	}
    qq[SHENDU]=1;
	For(i,down,up)gg[SHENDU][i]=gg[SHENDU-1][i*2]|gg[SHENDU-1][i*2+1];
	ddddfs(SHENDU+1,ned+1);
	qq[SHENDU]=2;
	For(i,down,up)gg[SHENDU][i]=gg[SHENDU-1][i*2]|(i?gg[SHENDU-1][i*2-1]:0);
	ddddfs(SHENDU+1,ned+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){ int x;scanf("%d",&x);gg[0][x+131072*4]=1;}
	ddddfs(1,0);
	For(i,0,20)
		if (qwq[i]==1)q1[++q1[0]]=1<<i-1;
		else if (qwq[i]==2)q1[++q1[0]]=-1<<i-1;
	printf("%d\n",q1[0]);
	For(i,1,q1[0])printf("%d ",q1[i]);
}
/*
20
*/