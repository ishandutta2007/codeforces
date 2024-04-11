//CF1086D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int f[3]={2,0,1},g[3]={1,2,0};
int W(char o){
	if(o=='R')
		return 0;
	if(o=='P')
		return 1;
	if(o=='S')
		return 2;
}
string s;
char ch[5];
int n,q,a[N];
int t[3][N<<2];
void ad(int e,int x,int y,int k=1,int l=1,int r=n){
	t[e][k]+=y;
	if(l==r)
		return;
	int h=l+r>>1;
	if(x<=h)
		ad(e,x,y,k<<1,l,h);
	else
		ad(e,x,y,k<<1|1,h+1,r);
}
int qu(int e,int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return t[e][k];
	int h=l+r>>1,o=0;
	if(L<=h)
		o+=qu(e,L,R,k<<1,l,h);
	if(h<R)
		o+=qu(e,L,R,k<<1|1,h+1,r);
	return o;
}
int fi(int e,int k=1,int l=1,int r=n){
	if(l==r)
		return l;
	int h=l+r>>1;
	if(t[e][k<<1])
		return fi(e,k<<1,l,h);
	return fi(e,k<<1|1,h+1,r);
}
int la(int e,int k=1,int l=1,int r=n){
	if(l==r)
		return l;
	int h=l+r>>1;
	if(t[e][k<<1|1])
		return la(e,k<<1|1,h+1,r);
	return la(e,k<<1,l,h);
}
int cnt(int e){
	if(!t[g[e]][1])
		return 0;
	if(!t[f[e]][1])
		return t[e][1];
	int x,y,o=0;
	x=fi(g[e]),y=fi(f[e]);
	if(x<y)
		o+=qu(e,x,y);
	x=la(f[e]),y=la(g[e]);
	if(x<y)
		o+=qu(e,x,y);
	return o;
}
void ans(){
	printf("%d\n",n-cnt(0)-cnt(1)-cnt(2));
}
int main()
{
	int i;
	cin>>n>>q>>s;
	s='_'+s;
	for(i=1;i<=n;i=i+1){
		a[i]=W(s[i]);
		ad(a[i],i,1);
	}
	ans();
	while(q--){
		scanf("%d%s",&i,ch);
		ad(a[i],i,-1);
		a[i]=W(ch[0]);
		ad(a[i],i,1);
		ans();
	}
	return 0;
}