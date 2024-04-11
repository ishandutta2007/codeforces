
// Problem : E. Messenger Simulator
// Contest : Educational Codeforces Round 80 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1288/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=300050;
int fa[N],go[N][2],sz[N];
void pull(int x){ sz[x]=sz[go[x][0]]+1+sz[go[x][1]];}
int pd(int x){ return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x)
{
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q) go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w) fa[w]=y;fa[x]=z;fa[y]=x;
	pull(y);pull(x);
}
int Calc(int x)
{
	if(pd(x)==-1) return 0;
	int d=pd(x);
	if(d==1) return Calc(fa[x])+sz[go[fa[x]][0]]+1;
	else return Calc(fa[x]);
}
int Rig(int x){ return go[x][1]?Rig(go[x][1]):x;}
void Splay(int x){ for(;~pd(x);rot(x)) if(~pd(fa[x])) rot(pd(x)==pd(fa[x])?fa[x]:x);}
int l[N],r[N];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)
	{
		l[i]=r[i]=i;
		if(i>1)
		{
			Splay(i-1);
			go[i-1][1]=i;
			fa[i]=i-1;
			pull(i);
			pull(i-1);
			rot(i);
		}
	}
	while(m--)
	{
		int i;
		scanf("%i",&i);
		int pos=Calc(i)+1+sz[go[i][0]];
		//printf("->%i %i\n",i,pos);
		r[i]=max(r[i],pos);
		l[i]=1;
		Splay(i);
		int L=go[i][0],R=go[i][1];
		go[i][0]=go[i][1]=0;
		fa[L]=fa[R]=0;
		int root=L;
		if(L && R)
		{
			int z=Rig(L);
			Splay(z);
			go[z][1]=R;
			fa[R]=z;
			pull(z);
			rot(R);
			root=R;
		}
		else if(L) root=L;
		else root=R;
		go[i][1]=root;
		fa[root]=i;
		pull(i);
	}
	for(int i=1;i<=n;i++)
	{
		int pos=Calc(i)+1+sz[go[i][0]];
		Splay(i);
		r[i]=max(r[i],pos);
	}
	for(int i=1;i<=n;i++) printf("%i %i\n",l[i],r[i]);
	return 0;
}