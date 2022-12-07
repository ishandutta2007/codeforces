#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int M=50005;
const int mo=1000000007;
int ch[M][10],fa[M];
int ed[M],nd,q[M];
bool vis[55][M][2][2];
int f[55][M][2][2];
char s[1005],t1[55],t2[55];
void build(){
	int h=0,t=0;
	For(i,0,9)
		if (ch[1][i]){
			q[++t]=ch[1][i];
			fa[ch[1][i]]=1;
		}
		else
			ch[1][i]=1;
	while (h!=t){
		int x=q[++h];
		For(i,0,9)
			if (ed[x]) ch[x][i]=x;
			else if (ch[x][i]){
				fa[ch[x][i]]=ch[fa[x]][i];
				q[++t]=ch[x][i];
			}
			else
				ch[x][i]=ch[fa[x]][i];
	}
}
int F(int d,int x,int fl1,int fl2){
	if (!d) return ed[x];
	if (vis[d][x][fl1][fl2])
		return f[d][x][fl1][fl2];
	int ans=0;
	vis[d][x][fl1][fl2]=1;
	For(i,fl1?t1[d]:0,fl2?t2[d]:9)
		ans=(ans+F(d-1,ch[x][i],fl1&(i==t1[d]),fl2&(i==t2[d])))%mo;
	return f[d][x][fl1][fl2]=ans;
}
int main(){
	scanf("%s%s%s",s+1,t1+1,t2+1);
	int l1=strlen(s+1);
	int l2=strlen(t1+1);
	int l3=l2/2;
	For(i,1,l2) t1[i]-='0';
	For(i,1,l2) t2[i]-='0';
	For(i,1,l1) s[i]-='0';
	reverse(t1+1,t1+l2+1);
	reverse(t2+1,t2+l2+1);
	nd=1;
	For(i,0,l1-l3){
		int x=1;
		For(j,1,l3){
			if (!ch[x][s[i+j]])
				ch[x][s[i+j]]=++nd;
			x=ch[x][s[i+j]];
		}
		ed[x]=1;
	}
	build();
	printf("%d\n",F(l2,1,1,1));
}