
// Problem : D. Ehab's Last Corollary
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[501],t,t1,i,j;
vector<int> gt[100001],eu; int par[100001],ti[100001],dep[100001];
int sparse[400001][20];
vector<pii> cr;
pii best;
int lca(ll a, ll b)
{
	
	int aa=min(ti[a],ti[b]),bb=max(ti[a],ti[b]);
	
	int sz=floor(log2(bb-aa+1));
	
	int ml=sparse[aa][sz];
	int mr=sparse[bb-(1<<sz)+1][sz];
	if (dep[ml]<dep[mr]) return ml; else return mr;
	
	return 0;
}
void dfs(int x, int p)
{
//	cout<<"dfs "<<x<<' '<<p<<endl;
//	cout<<eu.size()<<endl;
	par[x]=p;
	dep[x]=dep[p]+1;
	ti[x]=eu.size();
	eu.push_back(x);
	
	for (int g:gt[x]) if (g!=p)
	{
		if (par[g])
		{
			cr.push_back({x,g});
		}
		else
		{
		eu.push_back(x);
			dfs(g,x);
		}
		
	}
	eu.push_back(x);
	
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m>>k;
    for (i=1;i<=m;i++) 
    {
    	cin>>t>>t1;
    	gt[t].push_back(t1);
    	gt[t1].push_back(t);
    }
    
    dfs(1,1);
    
 //   cout<<eu.size()<<endl;
    for (i=0;i<eu.size();i++)
    {
     sparse[i][0]=eu[i];
//     cout<<eu[i]<<' ';
     }
    for (j=1;(1<<j)<=eu.size();j++)
    for (i=0;i<eu.size();i++) if (i+(1<<(j-1))<eu.size())
    {
    	if (dep[sparse[i][j-1]]<dep[sparse[i+(1<<(j-1))][j-1]])
    	{
    		sparse[i][j]=sparse[i][j-1];
    	}
    	else
    	{
    		sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
    	}
    	
    }
    else
    {
    	sparse[i][j]=sparse[i][j-1];
    }
    if (cr.size()==0)
    {
    	vector<int> buc[2];
    	for (i=1;i<=n;i++) buc[dep[i]%2].push_back(i);
    	if (buc[0].size()>buc[1].size())
    	{
    		cout<<1<<endl;
    		for (i=0;i<ceil(double(k)/2);i++) cout<<buc[0][i]<<' ';
    	}
    	else
    	{
    		
    		cout<<1<<endl;
    		for (i=0;i<ceil(double(k)/2);i++) cout<<buc[1][i]<<' ';
    	}
    }
    
    else
    {
    	
    best=cr[0];
    
    for (pii cur: cr)
    {
    	int lca_cur=lca(cur.fi,cur.se),lca_best=lca(best.fi,best.se);
    	if (dep[cur.fi]+dep[cur.se]-2*dep[lca_cur]<dep[best.fi]+dep[best.se]-2*dep[lca_best])
    	{
    		best=cur;
    	}
    }
    
    int lca_best=lca(best.fi,best.se);
    vector<int> p1,p2,fin;
    i=best.fi;
    while(i!=lca_best) 
    {
    	p1.push_back(i);
    	i=par[i];
    }
    i=best.se;
    while(i!=lca_best) 
    {
    	p2.push_back(i);
    	i=par[i];
    }
    
    for (i=0;i<p1.size();i++) fin.push_back(p1[i]);
    fin.push_back(lca_best);
    for (i=p2.size()-1;i>=0;i--) fin.push_back(p2[i]);
    if (fin.size()>k)
    {
    	cout<<1<<endl;
    	for (i=0;i<ceil(double(k)/2);i++) cout<<fin[i*2]<<' ';
    }
    else
    {
    	cout<<2<<endl<<fin.size()<<endl;
    	for (i=0;i<fin.size();i++) cout<<fin[i]<<' ';
    }
    
    
    }
    
}