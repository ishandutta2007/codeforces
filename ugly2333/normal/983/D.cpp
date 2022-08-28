//CF 983D
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
int mx(set<int>& s){
	if(s.empty())
		return 0;
	return *(s.rbegin());
}
struct node{
	set<int> S;
	int x,y;
}T[N<<3];
int m,f[N];
void modify(int L,int R,int X,int k=1,int l=1,int r=m){
	//cout<<L<<R<<X<<k<<l<<r<<endl;
	if(L<=l&&r<=R){
		if(X>=0)
			T[k].S.insert(X);
		else
			T[k].S.erase(-X);
	}
	else{
		int h=l+r>>1;
		if(L<=h)
			modify(L,R,X,k<<1,l,h);
		if(h<R)
			modify(L,R,X,k<<1|1,h+1,r);
	}
	int z=mx(T[k].S);
	T[k].x=max(z,min(T[k<<1].x,T[k<<1|1].x));
	T[k].y=max(z,max(T[k<<1].y,T[k<<1|1].y));
	if(T[k].y==z&&(f[z]||T[k].x>z))
		T[k].y=0;
}
void getans(int w=1,int k=1){
	//cout<<w<<k<<T[k].y<<endl;
	if(T[k].y<w)
		return;
	f[T[k].y]=1;
	int z=mx(T[k].S);
	w=max(w,z);
	getans(w,k<<1);
	getans(w,k<<1|1);
	T[k].x=max(z,min(T[k<<1].x,T[k<<1|1].x));
	T[k].y=max(z,max(T[k<<1].y,T[k<<1|1].y));
	if(T[k].y==z&&(f[z]||T[k].x>z))
		T[k].y=0;
}
int n,l[N],r[N],u[N],d[N];
map<int,int> M;
map<int,int>::iterator it;
vector<int> v[N];
int main()
{
	int i,j,e,o=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d%d%d%d",l+i,u+i,r+i,d+i);
	for(i=1;i<=n;i=i+1)
		M[l[i]]=1,M[r[i]]=1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m;
	for(i=1;i<=n;i=i+1)
		l[i]=M[l[i]],r[i]=M[r[i]]-1;
	M.clear();
	for(i=1;i<=n;i=i+1)
		M[u[i]]=1,M[d[i]]=1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++o;
	for(i=1;i<=n;i=i+1){
		v[M[u[i]]].push_back(i);
		v[M[d[i]]].push_back(-i);
	}
	for(i=1;i<=o;i=i+1){
		for(j=v[i].size();j--;){
			e=max(v[i][j],-v[i][j]);
			modify(l[e],r[e],v[i][j]);
		}
		//cout<<endl;
		while(T[1].y){
			getans();
		}
		//cout<<endl<<endl;
	}
	o=1;
	for(i=1;i<=n;i=i+1)
		o+=f[i];
	cout<<o;
	return 0;
}