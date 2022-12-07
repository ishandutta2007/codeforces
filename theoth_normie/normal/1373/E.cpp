
// Problem : Sum of Digits
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1373/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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
int cmp(string a, string b)
{
	if (a.length()-b.length()) return (a.length()<b.length());
	return (a<b);
}
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j;
string cres="",nxt;
string minus_one(string a)
{
	string res=a;
	for (int i=a.length()-1;i>=0;i--)
	{
		if (res[i]=='0') res[i]='9';
		else {res[i]--; if (res[0]=='0') res.erase(res.begin()); return res;}
	}
}
string build_base(int num)
{
	string res="";
	for (int i=0;i<num/9;i++) res.push_back('9');
	if (num%9) res.insert(res.begin(),char(48+num%9));
	return res;
}
void build (int cnt, int no0, int sum)
{
	
	if ((sum<=0)or(sum%cnt)) return;
	string res=build_base(sum/cnt);
	res=minus_one(res);
	for (int i=0;i<no0;i++) res.push_back('9');
	res.push_back(char(i+48));
//	cout<<"build "<<cnt<<' '<<no0<<' '<<sum<<endl;
//	cout<<res<<endl;
	if ((cres=="")or(cmp(res,cres))) cres=res;
}
void check (ll c1, ll c2, ll sum)
{
//	cout<<"check "<<c1<<' '<<c2<<' '<<sum<<endl;
//	cout<<i<<endl;
	if (c2==0)
	{
	if ((sum<0)or(sum%c1)) return;
		string res=build_base(sum/c1);
		res.push_back(char(i+48));
//		cout<<res<<endl;
	if ((cres=="")or(cmp(res,cres))) cres=res;
	}
	else
	for (int i=0;i<=150;i++)
	{
		build(c1+c2,i,sum-(9*i-1)*c1);
	}
}
int main()
{
//  ofile;
    fio;
    cin>>t;
//    cout<<t<<endl;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n>>k;
    	cres="";
    	for (i=0;i<10;i++)
    	{
    		ll sum=0,c1=0,c2=0;
    		for (j=0;j<=k;j++)
    		{
    			if (i+j<10) c1++;
    			else c2++;
    			sum+=(i+j)%10;
    		}
    		check(c1,c2,n-sum);
    	}
    	if (cres=="") cout<<-1; else cout<<cres;
    	cout<<endl;
    }
}