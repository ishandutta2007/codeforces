//CF 981G
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
const int MO = 998244353;
void AD(int& x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
void MUL(int& x,int y){
	x=(LL)x*y%MO;
}
struct node{
	int ans;
	int wmul,wadd;
	node(){
		ans=0;
		wmul=1,wadd=0;
	}
}T[1<<20];
int n;
void pushw(int k,int len){
	if(T[k].wmul>1){
		MUL(T[k<<1].ans,T[k].wmul);
		MUL(T[k<<1].wmul,T[k].wmul);
		MUL(T[k<<1].wadd,T[k].wmul);
		MUL(T[k<<1|1].ans,T[k].wmul);
		MUL(T[k<<1|1].wmul,T[k].wmul);
		MUL(T[k<<1|1].wadd,T[k].wmul);
		T[k].wmul=1;
	}
	if(T[k].wadd){
		int i=len>>1,j=len-i;
		MUL(i,T[k].wadd),MUL(j,T[k].wadd);
		AD(T[k<<1].ans,j);
		AD(T[k<<1].wadd,T[k].wadd);
		AD(T[k<<1|1].ans,i);
		AD(T[k<<1|1].wadd,T[k].wadd);
		T[k].wadd=0;
	}
}
void mul2(int L,int R,int k=1,int l=1,int r=n){
	//if(k==1)cout<<'M'<<L<<R<<endl;
	pushw(k,r-l+1);
	if(L<=l&&r<=R){
		MUL(T[k].ans,2);
		T[k].wmul=2;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		mul2(L,R,k<<1,l,h);
	if(h<R)
		mul2(L,R,k<<1|1,h+1,r);
	T[k].ans=(T[k<<1].ans+T[k<<1|1].ans)%MO;
}
void add1(int L,int R,int k=1,int l=1,int r=n){
	//if(k==1)cout<<'A'<<L<<R<<endl;
	pushw(k,r-l+1);
	if(L<=l&&r<=R){
		AD(T[k].ans,r-l+1);
		T[k].wadd=1;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		add1(L,R,k<<1,l,h);
	if(h<R)
		add1(L,R,k<<1|1,h+1,r);
	T[k].ans=(T[k<<1].ans+T[k<<1|1].ans)%MO;
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k].ans;
	pushw(k,r-l+1);
	int h=l+r>>1,s=0;
	if(L<=h)
		AD(s,query(L,R,k<<1,l,h));
	if(h<R)
		AD(s,query(L,R,k<<1|1,h+1,r));
	return s;
}
set<pair<int,int> > S[N];
set<pair<int,int> >::iterator it;
vector<pair<int,int> > v;
int main()
{
	int q,l,r,x;
	pair<int,int> p;
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d%d",&x,&l,&r);
		if(x==2)
			printf("%d\n",query(l,r));
		else{
			scanf("%d",&x);
			p=make_pair(l,r);
			if(S[x].find(p)!=S[x].end())
				mul2(l,r);
			else{
				it=S[x].lower_bound(p);
				if(it!=S[x].begin()){
					it--;
					if((*it).second>=l){
						if((*it).second>=r){
							mul2(l,r);
							continue;
						}
						mul2(l,(*it).second);
						p.first=(*it).first;
						l=(*it).second+1;
						S[x].erase(*it);
					}
				}
				v.clear();
				for(it=S[x].lower_bound(p);it!=S[x].end()&&(*it).second<=r;it++){
					if(l<(*it).first)
						add1(l,(*it).first-1);
					mul2((*it).first,(*it).second);
					l=(*it).second+1;
					v.push_back(*it);
				}
				if(it!=S[x].end()){
					if((*it).first>r){
						if(l<=r)
							add1(l,r);
					}
					else{
						if(l<(*it).first)
							add1(l,(*it).first-1);
						mul2((*it).first,r);
						p.second=(*it).second;
						v.push_back(*it);
					}
				}
				else{
					if(l<=r)
						add1(l,r);
				}
				for(l=v.size();l--;)
					S[x].erase(v[l]);
				S[x].insert(p);
				//cout<<p.first<<p.second<<endl<<endl;
			}
		}
	}
	return 0;
}