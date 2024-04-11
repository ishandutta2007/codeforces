//CF 74D
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
const int N = 111111;
int tot=1;
struct node{
	int x;
	int ls,rs;
}T[N<<6];
void addnode(int k){
	if(!T[k].ls)
		T[k].ls=++tot;
	if(!T[k].rs)
		T[k].rs=++tot;
}
int n,q;
void modify(int p,int v,int k=1,int l=1,int r=n){
	T[k].x+=v;
	if(l==r)
		return;
	addnode(k);
	int h=l+r>>1;
	if(p<=h)
		modify(p,v,T[k].ls,l,h);
	else
		modify(p,v,T[k].rs,h+1,r);
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k].x;
	if(r<L||R<L||R<l||!T[k].x)
		return 0;
	addnode(k);
	int h=l+r>>1;
	return query(L,R,T[k].ls,l,h)+query(L,R,T[k].rs,h+1,r);
}
map<int,int> M;
set<int> U;
set<int>::iterator it;
set<pair<int,int> > S;
pair<int,int> pp;
int main()
{
	int t,x,y,z;
	scanf("%d%d",&n,&q);
	U.insert(0),U.insert(n+1);
	S.insert(make_pair(n+1,n+1));
	while(q--){
		scanf("%d",&t);
		if(t){
			if(!M[t]){
				pp=*S.rbegin();
				S.erase(pp);
				x=pp.first,y=pp.second,z=y-x/2;
				M[t]=z;
				U.insert(z);
				modify(z,1);
				x=y-x;
				S.insert(make_pair(z-x,z));
				S.insert(make_pair(y-z,y));
			}
			else{
				z=M[t];
				M[t]=0;
				U.erase(z);
				modify(z,-1);
				it=U.lower_bound(z);
				y=*it,it--,x=*it;
				S.erase(make_pair(z-x,z));
				S.erase(make_pair(y-z,y));
				S.insert(make_pair(y-x,y));
			}
		}
		else{
			scanf("%d%d",&x,&y);
			cout<<query(x,y)<<endl;
		}
	}
	return 0;
}