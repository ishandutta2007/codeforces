#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,p,cnt,g;
int s[10],q[10][1000005][3],front[10],rear[10],lst[10],ans[10];
char a[1005][1005];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

void bfs(int x){
	if(front[x]>=rear[x]) return;
	while(front[x]<rear[x]){
		int tx=q[x][front[x]][0],ty=q[x][front[x]][1],stp=q[x][front[x]++][2],dx,dy;
		if(stp-lst[x]==s[x]){
			front[x]--;
			break;
		}
		for(int i=0;i<4;i++){
			dx=tx+dir[i][0],dy=ty+dir[i][1];
			if(dx<1||dx>n||dy<1||dy>m||a[dx][dy]!='.') continue;
			a[dx][dy]=x+'0',cnt--;
			q[x][rear[x]][0]=dx,q[x][rear[x]][1]=dy,q[x][rear[x]++][2]=stp+1;
		}
	}
	if(front[x]>=rear[x]) g++;
	lst[x]+=s[x];
}

int main(){
	n=readint(); m=readint(); p=readint();
	for(int i=1;i<=p;i++) s[i]=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>='1'&&a[i][j]<=p+'0') q[a[i][j]-'0'][rear[a[i][j]-'0']][0]=i,q[a[i][j]-'0'][rear[a[i][j]-'0']++][1]=j;
		}
	}
	while(g<p){
		for(int i=1;i<=p;i++) bfs(i);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>='1'&&a[i][j]<=p+'0') ans[a[i][j]-'0']++;
	for(int i=1;i<=p;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}