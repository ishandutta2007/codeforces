#include<bits/stdc++.h>
using namespace std;
//const int maxm=5,maxn=4,eps=6;
const int maxm=35,maxn=9,eps=20;
const int N=15,a=maxn*4-1,b=maxm*4+eps,c=maxm*4+eps;
int n,G[N][N],mask[N];
int jump_down=c-2,climb_up=2;
char F[c+1][b+1][a+1];
void addedge(int i,int j){
	int k;
	for(k=climb_up+1;k<=jump_down+1;k++)
		F[k][jump_down][i*4-1]='.';
	for(k=min(i*4-1,j*4-3);k<=max(i*4-1,j*4-3);k++)
		F[climb_up+1][jump_down][k]='.';
	for(k=climb_up;k<=jump_down;k++)
		F[climb_up+1][k][j*4-3]='.';
	climb_up+=2,jump_down-=2;
}
int main(){
	int i,j,k,S,T;
	scanf("%d",&n);
	for(i=1;i<=c;i++)for(j=1;j<=b;j++)for(k=1;k<=a;k++)F[i][j][k]='#';
	for(i=1;i<=n;i++){
		for(j=1;j<b;j++)F[j+1][j][i*4-2]='.';
		for(j=1;j+1<b;j++)F[j+2][j][i*4-2]='.';
		F[c][c-1][i*4-2]=i+'0';
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		scanf("%d",&G[i][j]);
		if(G[i][j])mask[i]|=1<<j;
	}
	for(i=1;i<=n;i++)mask[i]|=1<<i;
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(mask[i]>>j&1)mask[i]|=mask[j];
	for(i=1;i<=n;i++)mask[i]>>=1;
	vector<char>fix(1<<n);
	for(S=1;S<1<<n;S++){
		T=S;
		for(k=1;k<=n;k++)if(S>>(k-1)&1)T&=mask[k];
		if(S==T)fix[S]=true;
	}
	for(i=0;i<1<<n;i++)if(fix[i])for(j=i+1;j<1<<n;j++)if((j&i)==i&&fix[j]){fix[i]=0;break;}
	for(i=0;i<1<<n;i++)if(fix[i]){
		vector<int>vs;
		for(j=1;j<=n;j++)if(i>>(j-1)&1)vs.push_back(j);
		if(vs.size()>1)for(j=0;j<vs.size();j++)for(k=0;k<vs.size();k++)G[vs[j]][vs[k]]=(k==(j+1)%vs.size());
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(G[i][j])addedge(i,j);
	printf("%d %d %d\n",a,b,c);
	for(i=c;i>=1;i--){
		for(j=1;j<=b;j++){
			for(k=1;k<=a;k++)putchar(F[i][j][k]);
			putchar('\n');
		}
		putchar('\n');
	}
}