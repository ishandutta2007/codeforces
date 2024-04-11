#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
/*int32_t main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
	    //cout<<curr<<" curr "<<l[curr]<<" l[curr] "<<r[curr]<<" r[curr] "<<endl;
		int l1,r1;
		cin>>l1>>r1;
		l1--;
		pair <int,int> z=split(curr,l1);
		//cout<<curr<<" curr "<<l[curr]<<" l[curr] "<<r[curr]<<" r[curr] "<<endl;
		pair <int,int> o=split(z.second,r1-l1);
		//cout<<curr<<" curr "<<l[curr]<<" l[curr] "<<r[curr]<<" r[curr] "<<endl;
		//cout<<" ok "<<endl;
		//cout<<z.first<<' '<<o.first<<' '<<o.second<<endl;
		int h=merg(o.first,z.first);
		//cout<<h<<" h "<<endl;
		curr=merg(h,o.second);
		//cout<<-1<<' '<<-1<<' '<<l[2]<<' '<<r[2]<<" l r "<<endl;
		//cout<<curr<<" curr "<<l[curr]<<" l[curr] "<<r[curr]<<" r[curr] "<<endl;
	}
	for(int i=0;i<n;++i)
    {
        pair <int,int> z=split(curr,1);
        cout<<val[z.first]+1<<' ';
        curr=z.second;
    }
	return 0;
}*/

using namespace std;
#define int long long
const int p=998244353;
const int maxn=4e5+5;
const int maxn1=2e5+5;
int l[maxn1];int r[maxn1];int val[maxn1];int pri[maxn1];int sz[maxn1];
void rec(int node)
{
	if(node==(-1)) return;
	sz[node]=1;
	if(l[node]!=(-1)) sz[node]+=sz[l[node]];
	if(r[node]!=(-1)) sz[node]+=sz[r[node]];
}
int getsize(int node)
{
	if(node==(-1)) return 0;
	return sz[node];
}
int merg(int node1,int node2)
{
    //cout<<node1<<' '<<node2<<' '<<l[2]<<' '<<r[2]<<" l r "<<endl;
	if(node1==(-1)) return node2;
	if(node2==(-1)) return node1;
	if(pri[node1]>pri[node2])
	{
		int o=merg(r[node1],node2);
		r[node1]=o;
		//cout<<node1<<' '<<node2<<' '<<l[2]<<' '<<r[2]<<" l r "<<endl;
		rec(node1);
		return node1;
	}
	else
	{
		int o=merg(node1,l[node2]);
		l[node2]=o;
		//cout<<node1<<' '<<node2<<' '<<l[2]<<' '<<r[2]<<" l r "<<endl;
		rec(node2);
		return node2;
	}
}
pair <int,int> split(int node,int x)
{
    //cout<<node<<" node "<<getsize(node)<<" sz "<<x<<" x "<<endl;
    //if(node!=(-1)) cout<<l[node]<<' '<<r[node]<<endl;
	assert(x<=getsize(node));
	if(node==(-1)) return {-1,-1};
	if(sz[node]==x) return {node,-1};
	int o=getsize(l[node]);
	//cout<<o<<" o "<<endl;
	if(o<x)
	{
		pair <int,int> ans1=split(r[node],x-o-1);
		r[node]=ans1.first;
		rec(node);
		return {node,ans1.second};
	}
	else
	{
		pair <int,int> ans1=split(l[node],x);
		l[node]=ans1.second;
		rec(node);
		return {ans1.first,node};
	}
}
mt19937 rnd;
int fact[maxn];
int invf[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(48933902);
    for(int i=0;i<maxn1;++i) {l[i]=(-1);r[i]=(-1);pri[i]=rnd();val[i]=i;sz[i]=1;}
    int curr=0;
	for(int i=0;i<maxn1-1;++i) curr=merg(curr,i+1);
    int u1=1;
    for(int i=0;i<maxn;++i) {fact[i]=u1;invf[i]=inv(fact[i]);u1*=(i+1);u1%=p;}
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        pair <int,int> a[m];set <int> o;
        for(int i=0;i<m;++i) {cin>>a[i].first>>a[i].second;
        pair <int,int> z=split(curr,a[i].second-1);
        pair <int,int> z2=split(z.second,1);
        pair <int,int> z3=split(z2.second,a[i].first-a[i].second-1);
        pair <int,int> z4=split(z3.second,1);
        o.insert(z2.first);
        curr=merg(merg(merg(merg(z.first,z4.first),z2.first),z3.first),z4.second);
        }
        cout<<c(2*n-o.size()-1,n)<<'\n';
    }
    return 0;
}