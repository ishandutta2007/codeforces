#include <stdio.h>
#include <vector>
#include <bitset>
using namespace std;
#define pb push_back
const int N=10050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
vector<int> add[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int x)
{
	if(qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ add[c].pb(x);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
}
bitset<N> sol;
void DFS(int c, int ss, int se, bitset<N> tmp)
{
	for(int i=0;i<add[c].size();i++) tmp|=tmp<<add[c][i];
	if(ss==se){ sol|=tmp;return;}
	int mid=ss+se>>1;
	DFS(ls[c],ss,mid,tmp);
	DFS(rs[c],mid+1,se,tmp);
}
bitset<N> tmp;
int main()
{
	int n,q,l,r,x,i;
	scanf("%i %i",&n,&q);
	Build(root,1,n);
	while(q--) scanf("%i %i %i",&l,&r,&x),Set(root,1,n,l,r,x);
	tmp.set(0);
	DFS(root,1,n,tmp);
	vector<int> ans;
	for(i=1;i<=n;i++) if(sol.test(i)) ans.pb(i);
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%i ",ans[i]);
	printf("\n");
	return 0;
}