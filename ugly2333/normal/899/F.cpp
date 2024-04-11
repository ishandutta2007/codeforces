//CF 899F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
const int R = 66;
int n,q,ans[N],w[N],h[N];
char ch[N],cc;
set<int> S[R];
set<int>::iterator it,i1,i2;
int T[N<<2];
void build(int k=1,int l=1,int r=n){
	T[k]=r-l+1;
	if(l==r)
		return;
	int x=l+r>>1;
	build(k<<1,l,x);
	build(k<<1|1,x+1,r);;
}
void modify(int p,int k=1,int l=1,int r=n){
	T[k]--;
	if(l==r)
		return;
	int x=l+r>>1;
	if(p<=x)
		modify(p,k<<1,l,x);
	else
		modify(p,k<<1|1,x+1,r);
}
int query(int p,int k=1,int l=1,int r=n){
	if(l==r)
		return l;
	int x=l+r>>1;
	if(p<=T[k<<1])
		return query(p,k<<1,l,x);
	return query(p-T[k<<1],k<<1|1,x+1,r);
}
int main()
{
	int i,j,c,g;
	c=0;
	for(i='0';i<='9';i=i+1)
		w[i]=c++;
	for(i='A';i<='Z';i=i+1)
		w[i]=c++;
	for(i='a';i<='z';i=i+1)
		w[i]=c++;
	scanf("%d%d%s",&n,&q,ch+1);
	for(i=1;i<=n;i=i+1)
		S[w[ch[i]]].insert(i);
	build();
	while(q--){
		scanf("%d%d%c%c",&i,&j,ch,&cc);
		i=query(i),j=query(j),c=w[cc];
		i1=S[c].lower_bound(i),i2=S[c].upper_bound(j);
		g=0;
		for(it=i1;it!=i2;it++){
			h[g++]=*it;
			ans[*it]=1;
			modify(*it);
		}
		for(i=0;i<g;i=i+1)
			S[c].erase(h[i]);
	}
	for(i=1;i<=n;i=i+1)
		if(!ans[i])
			cout<<ch[i];
	return 0;
}