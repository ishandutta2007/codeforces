#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll long long
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=100;
ll f[N][N][N][3],n,pos[3][N],pre[N][3],a[N];	char s[N];
void add(ll &x,ll y){	x=min(x,y);	}
ll get(ll x,ll y,ll z,ll pyop){ 	return max(0ll,pre[pyop][0]-x)+max(0ll,pre[pyop][1]-y)+max(0ll,pre[pyop][2]-z)-1;	}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();	scanf("%s",s+1);
	memset(f,60,sizeof f);
	For(i,1,n){
		if (s[i]=='V')	a[i]=0,add(f[1][0][0][0],i-1),pos[0][++pos[0][0]]=i;
		lf (s[i]=='K')	a[i]=1,add(f[0][1][0][1],i-1),pos[1][++pos[1][0]]=i;
		else a[i]=2,add(f[0][0][1][2],i-1),pos[2][++pos[2][0]]=i;
		memcpy(pre[i],pre[i-1],sizeof pre[i-1]);	pre[i][a[i]]++;
	}
	For(i,0,pos[0][0])	For(j,0,pos[1][0])	For(k,0,pos[2][0])	For(cur,0,2){
		if (i<pos[0][0])			add(f[i+1][j][k][0],f[i][j][k][cur]+get(i,j,k,pos[0][i+1]));
		if (j<pos[1][0]&&cur!=0)	add(f[i][j+1][k][1],f[i][j][k][cur]+get(i,j,k,pos[1][j+1]));
		if (k<pos[2][0])			add(f[i][j][k+1][2],f[i][j][k][cur]+get(i,j,k,pos[2][k+1]));
	}writeln(min(min(f[pos[0][0]][pos[1][0]][pos[2][0]][0],f[pos[0][0]][pos[1][0]][pos[2][0]][1]),f[pos[0][0]][pos[1][0]][pos[2][0]][2]));
}
//nn < 76VK