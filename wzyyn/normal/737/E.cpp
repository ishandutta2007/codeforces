#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=505;
int n,m,B,ans;
int co[N],sx[N],sy[N];
int mp[N][N],id[N],fl[N];
int mat[N],to[N];
bool vis[N],Mat[N];
bool dfs(int x){
	For(i,1,n+m)
		if (mp[x][i]&&!vis[i]){
			vis[i]=1;
			if (!mat[i]||dfs(mat[i]))
				return mat[i]=x,to[x]=i,1;//return 1;
		}
	return 0;
}
struct node{
	int x,y,st,T;
}Ans[5000005];
int ans_top;
const int OUT_BUF=100000000;
char out[OUT_BUF];
int out_top;
void write(int x){
	if (!x){
		out[out_top++]='0';
		return;
	}
	static int a[15],top;
	for (top=0;x;a[++top]=x%10,x/=10);
	for (;top;out[out_top++]=a[top--]+'0');
}
void writespace(int x){
	write(x);
	out[out_top++]=' ';
}
void writeln(int x){
	write(x);
	out[out_top++]='\n';
}
int main(){
	scanf("%d%d%d",&n,&m,&B);
	For(i,1,m) scanf("%d",&co[i]);
	For(i,1,m) id[i]=i;
	For(i,1,n){
		int cnt,x,y;
		scanf("%d",&cnt);
		while (cnt--){
			scanf("%d%d",&x,&y);
			mp[i][x]=y; sx[i]+=y; sy[x]+=y;
		}
	}
	For(i,1,m) For(j,i+1,m)
		if (sy[id[i]]>sy[id[j]])
			swap(id[i],id[j]);
	int p=m;
	for (;p&&B>=co[id[p]];B-=co[id[p]],--p);
	For(i,1,n) ans=max(ans,sx[i]);
	For(i,1,p) ans=max(ans,sy[id[i]]);
	For(i,p+1,m) ans=max(ans,(sy[id[i]]+1)/2); 
	For(i,p+1,m){
		sy[id[i]]=0; fl[id[i]]=1;
		For(j,1,n){
			int x=id[i],y=x+m,v=mp[j][x];
			mp[j][x]=mp[j][y]=v/2;
			if (v&1) mp[j][sy[x]<sy[y]?x:y]++;
			sy[x]+=mp[j][x]; sy[y]+=mp[j][y];
		}
	}
	writeln(ans);
	For(i,1,m) write(fl[i]);
	out[out_top++]='\n';
	m*=2;
	For(i,1,n) For(j,1,n){
		mp[i][j+m]=ans-max(sx[i],sy[j+m]);
		sx[i]+=mp[i][j+m];
		sy[j+m]+=mp[i][j+m];
	} 
	For(i,1,m) For(j,1,m){
		mp[i+n][j]=ans-max(sx[i+n],sy[j]);
		sx[i+n]+=mp[i+n][j];
		sy[j]+=mp[i+n][j];
	}
	For(i,1,m) For(j,1,n){
		mp[i+n][j+m]=ans-max(sx[i+n],sy[j+m]);
		sx[i+n]+=mp[i+n][j+m];
		sy[j+m]+=mp[i+n][j+m];
	}
	//For(i,1,n+m) For(j,1,n+m)
	//	printf("%d%c",mp[i][j],j==n+m?'\n':' ');
	For(i,1,n+m) Mat[i]=1;
	for (int T=0;T<ans;){
		For(i,1,n+m) if (Mat[i]){
			memset(vis,0,sizeof(vis));
			dfs(i); Mat[i]=0;
		}
		int mn=1e9;
		For(i,1,n+m) if (to[i])
			mn=min(mn,mp[i][to[i]]);
		For(i,1,n+m) if (to[i]){
			if (i<=n&&to[i]<=m)
				Ans[++ans_top]=(node){i,to[i],T,mn};
			if (!(mp[i][to[i]]-=mn))
				Mat[i]=1,mat[to[i]]=0;
		}
		T+=mn;
	}
	writeln(ans_top);
	For(i,1,ans_top){
		writespace(Ans[i].x);
		writespace((Ans[i].y-1)%(m/2)+1);
		writespace(Ans[i].st);
		writeln(Ans[i].T); 
	}
	fwrite(out,1,out_top,stdout);
}