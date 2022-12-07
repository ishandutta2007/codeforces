#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
struct P{
	int x,y;
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}p[2005];
int n,vis[2005];
char s[2005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	scanf("%s",s+1); s[n-1]='L';
	int id=1;
	For(i,2,n) if (p[i]<p[id]) id=i;
	printf("%d ",id); vis[id]=1;
	For(i,1,n-1){
		int now=-1;
		For(j,1,n) if (!vis[j])
			if (now==-1) now=j;
			else if ((s[i]=='R'?-1:1)*((p[j]-p[id])*(p[now]-p[id]))>0) now=j;
		vis[id=now]=1; printf("%d ",now);
	}
}