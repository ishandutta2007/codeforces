
// Problem : F. Two Different
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#define p1 first
#define p2 second.first
#define p3 second.second
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<int> buc[41];
vector<pii> res;
int main()
{
//  ofile;
    fio;
    cin>>n;
    j=0;
    m=0;
    for (i=20;i>=0;i--)
    {
    	if (j+(1<<i)<=n) 
    	{
//    		cout<<i<<' ';
    		m++;
    		for (k=j+1;k<=j+(1<<i);k++) buc[m].push_back(k);
    		j+=(1<<i);
    	}
    }
 //   cout<<endl;
    for (i=1;i<=m;i++)
    {
    	for (j=1;(1<<j)<=buc[i].size();j++)
    	for (k=0;k+(1<<j)<=buc[i].size();k+=(1<<j))
    	for (t=0;t<(1<<(j-1));t++)
    	{
    		res.push_back({buc[i][k+t],buc[i][k+t+(1<<(j-1))]});
    	}
    }
    for (i=m;i>=3;i--)
    {
    	while(buc[i-1].size()>buc[i].size())
    	{
    		int tmp=buc[i].size();
    		for (j=0;j<tmp;j++)
    		{
    			res.push_back({buc[1][buc[1].size()-1],buc[i][j]});
    			buc[i].push_back(buc[1][buc[1].size()-1]);
    			buc[1].pop_back();
    		}
    	}
    	for (j=0;j<buc[i].size();j++) {res.push_back({buc[i-1][j],buc[i][j]}); buc[i-1].push_back({buc[i][j]});}
    	buc[i].clear();
    }
    cout<<res.size()<<endl;
    for (pii pp : res) cout<<pp.fi<<' '<<pp.se<<endl;
}