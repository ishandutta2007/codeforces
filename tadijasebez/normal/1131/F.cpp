#include <bits/stdc++.h>
using namespace std;
const int N=150050;
int go[N][2],fa[N];
int pd(int x){ return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x)
{
	int f=fa[x],g=fa[f],tf=pd(x),tg=pd(f),y=go[x][tf^1];
	if(tg!=-1) go[g][tg]=x;go[f][tf]=y;go[x][tf^1]=f;
	fa[x]=g;fa[f]=x;if(y) fa[y]=f;
}
void splay(int x){ for(;pd(x)!=-1;rot(x)) if(pd(fa[x])!=-1) rot(pd(fa[x])==pd(x)?fa[x]:x);}
int find(int x){ return go[x][1]?find(go[x][1]):x;}
void print(int x){ if(!x) return;print(go[x][0]);printf("%i ",x);print(go[x][1]);}
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&x,&y);
		splay(x);splay(y);
		int w=find(x);
		splay(w);go[w][1]=y;fa[y]=w;
	}
	splay(1);
	print(1);
	return 0;
}