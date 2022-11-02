#include<bits/stdc++.h>
using namespace std;
char s[1009];
int n,m,k,a[1009][1009];
struct pp{int X,Y;char t;}p[100009];
queue<pp> q;
char ans[109];int cnt;

int main(){
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=1;j<=m;j++){
			if(s[j-1]=='.') a[i][j]=0;
			if(s[j-1]=='#') a[i][j]=1;
			if(s[j-1]>='A'&&s[j-1]<='Z'){
				a[i][j]=0;
				q.push((pp){i,j,s[j-1]});
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		char c;int d;
		cin>>c>>d;
		if(c=='N') p[i].X=-d,p[i].Y=0;
		if(c=='S') p[i].X=d,p[i].Y=0;
		if(c=='E') p[i].X=0,p[i].Y=d;
		if(c=='W') p[i].X=0,p[i].Y=-d;
	}
	cnt=0;
	while(!q.empty()){
		pp cur=q.front();q.pop();int flag=1;
		for(int i=1;i<=k;i++){
			pp tmp=(pp){cur.X+p[i].X,cur.Y+p[i].Y,cur.t};pp nxt=tmp;
			if(tmp.X<1||tmp.X>n||tmp.Y<1||tmp.Y>m){flag=0;break;}
			if(p[i].X>0||p[i].Y>0) swap(cur,tmp);
			int area=a[cur.X][cur.Y]-a[cur.X][tmp.Y-1]-a[tmp.X-1][cur.Y]+a[tmp.X-1][tmp.Y-1];
			if(area>0){flag=0;break;}
			cur=nxt;
		}
		if(flag) ans[++cnt]=cur.t;
	}
	sort(ans+1,ans+cnt+1);
	for(int i=1;i<=cnt;i++) printf("%c",ans[i]);
	if(!cnt) printf("no solution\n");
	return 0;
}