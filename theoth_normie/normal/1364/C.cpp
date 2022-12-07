
// Problem : A. XXXXX
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/A
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
ll n,m,k,c[501],arr[100001],t,t1,i,j,res,hol=0;
ll pre[100001];
ll mex[10001];
vector<ll> vll;
int main()
{
//  ofile;
    fio;
    cin>>n;
    t=0; t1=0;
    for (i=1;i<=n;i++) arr[i]=-1;
    for (i=1;i<=n;i++)
    {
    	t1=t;
    	cin>>t;
 //   	cout<<t<<' '<<t1<<endl;
    	if (t-t1)
    	{
    		for (j=t-1;j>t1;j--) vll.push_back(j);
    		arr[i]=t1;
    	}
    	else hol++;
    }
    j=0;
    for (i=1;i<=n;i++)
    {
    if (arr[i]==-1)
    {
    	if (j<vll.size()) {arr[i]=vll[j]; j++;} else arr[i]=1e6;
    }
    
    	cout<<arr[i]<<' ';
    	}
    
}