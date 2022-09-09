#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
struct Range
{
	int l,r;
	ll x;
	Range(){}
	Range(int a, int b, ll c){ l=a,r=b,x=c;}
	int size(){ return r-l+1;}
	bool operator < (Range b) const{ return l<b.l;}
	bool operator == (Range b) const{ return l==b.l;}
};
set<Range> Set;
set<Range>::iterator it,it1;
Range tmp;
vector<Range> v;
ll seed,sol;
int n,m,vmax;
void Cut(int l)
{
	it=Set.upper_bound(Range(l,n+1,0));
	if(it==Set.begin()) return;
	it--;
	tmp=*it;
	if(tmp.r>l && tmp.l<=l)
	{
		Set.erase(it);
		Set.insert(Range(tmp.l,l,tmp.x));
		Set.insert(Range(l+1,tmp.r,tmp.x));
	}
}
void Split(int l, int r){ Cut(l-1);Cut(r);}
void Increase(int l, int r, ll x)
{
	for(it=Set.lower_bound(Range(l,-1,0));it!=Set.upper_bound(Range(r,n+1,0));)
	{
		tmp=*it;it++;
		Set.erase(tmp);
		tmp.x+=x;
		Set.insert(tmp);
	}
}
void Place(int l, int r, ll x)
{ 
	Set.erase(Set.lower_bound(Range(l,-1,0)),Set.upper_bound(Range(r,n+1,0)));
	Set.insert(Range(l,r,x));
}
void BuildVector(int l, int r){ v.clear();for(it=Set.lower_bound(Range(l,-1,0));it!=Set.upper_bound(Range(r,n+1,0));it++) v.push_back(*it);}
ll Rnd()
{
	ll ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
void Swap(int &a, int &b){ a^=b;b^=a;a^=b;}
int pow(int x, int k, int mod){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
bool Compare(Range a, Range b){ return a.x<b.x;}
int main()
{
	int i,t,l,r,x,mod;
	scanf("%i %i %lld %i",&n,&m,&seed,&vmax);
	for(i=1;i<=n;i++)Set.insert(Range(i,i,(Rnd()%vmax)+1));
	while(m--){
		t=(Rnd()%4)+1;
		l=(Rnd()%n)+1;
		r=(Rnd()%n)+1;
		if(l>r) Swap(l,r);
		Split(l,r);
		if(t==1){
			x=(Rnd()%vmax)+1;
			Increase(l,r,x);
		}
		if(t==2){
			x=(Rnd()%vmax)+1;
			Place(l,r,x);
		}
		if(t==3){
			x=(Rnd()%(r-l+1))+1;
			BuildVector(l,r);
			sort(v.begin(),v.end(),Compare);
			int mess=0;
			for(i=0;i<v.size();i++){
				mess+=v[i].size();
				if(mess>=x){
					printf("%lld\n",v[i].x);
					break;
				}
			}
		}
		if(t==4){
			x=(Rnd()%vmax)+1;
			mod=(Rnd()%vmax)+1;
			BuildVector(l,r);
			sol=0;
			for(i=0;i<v.size();i++){
				sol+=(ll)pow(v[i].x%mod,x,mod)*v[i].size()%mod;
				sol%=mod;
			}
			printf("%lld\n",sol);
		}
	}
	return 0;
}