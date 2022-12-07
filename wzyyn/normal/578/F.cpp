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
const int N=205;
char s[N][N];
int id[N][N],fa[N*N];
int Id[N*N],a[N][N];
int n,m,nd,mo;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int Det(int n){
	For(i,1,n) For(j,1,n)
		if (a[i][j]<0) a[i][j]+=mo;
	int ans=1;
	For(i,1,n){
		int p=-1;
		For(j,i,n)
			if (a[j][i]){
				p=j;
				break;
			}
		if (p==-1) return 0;
		if (p!=i){
			ans=1ll*ans*(mo-1)%mo;
			For(j,i,n) swap(a[i][j],a[p][j]);
		}
		ans=1ll*ans*a[i][i]%mo;
		int Inv=power(a[i][i],mo-2);
		For(j,i+1,n){
			int val=mo-1ll*Inv*a[j][i]%mo;
			For(k,i,n) a[j][k]=(a[j][k]+1ll*val*a[i][k])%mo;
		}
	}
	return ans;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return 0;
	return fa[x]=y,1;
}
void adde(int x,int y){
	x=Id[get(x)]; y=Id[get(y)];
	a[x][x]++; a[y][y]++;
	a[x][y]--; a[y][x]--;
}
int solve(int tp){
	nd=0;
	For(i,0,n) For(j,0,m)
		if ((i+j+tp)&1) id[i][j]=++nd;
	For(i,1,nd) fa[i]=i;
	For(i,1,n) For(j,1,m){
		char c=((i+j+tp)&1?'\\':'/');
		if (s[i][j]!=c) continue;
		if ((i+j+tp)&1)
			if (!merge(id[i-1][j-1],id[i][j])) return 0;
			else;
		else if (!merge(id[i][j-1],id[i-1][j])) return 0;
	}
	memset(Id,0,sizeof(Id));
	memset(a,0,sizeof(a));
	For(i,1,nd) if (get(i)==i) Id[i]=++*Id;
	if ((*Id)>202) return 0;
	For(i,1,n) For(j,1,m) if (s[i][j]=='*')
		if ((i+j+tp)&1) adde(id[i-1][j-1],id[i][j]);
		else adde(id[i][j-1],id[i-1][j]);
	return Det((*Id)-1);
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	For(i,1,n) scanf("%s",s[i]+1);
	printf("%d",(solve(0)+solve(1))%mo);
}