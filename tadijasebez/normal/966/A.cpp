#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
bool ckmax(int &a, int b){ a=max(a,b);return a==b;}
bool ckmin(int &a, int b){ a=min(a,b);return a==b;}
bool ckmax(ll &a, ll b){ a=max(a,b);return a==b;}
bool ckmin(ll &a, ll b){ a=min(a,b);return a==b;}
const int mod=1e9+7;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int inv(int x){ return pow(x,mod-2);}
void add(int &a, int b){ a+=b;if(a>=mod) a-=mod;}
void sub(int &a, int b){ a-=b;if(a<0) a+=mod;}
void mul(int &a, int b){ a=(ll)a*b%mod;}
void div(int &a, int b){ mul(a,inv(b));}
vector<int> el,st;
const int inf=1e9+7;
int dist(int a, int b){ return max(a,b)-min(a,b);}
int main()
{
	int n,m,esz,lsz,q,v,i,x;
	scanf("%i %i %i %i %i",&n,&m,&lsz,&esz,&v);
	while(lsz--) scanf("%i",&x),st.pb(x);
	while(esz--) scanf("%i",&x),el.pb(x);
	sort(st.begin(),st.end());
	sort(el.begin(),el.end());
	scanf("%i",&q);
	int x1,y1,x2,y2;
	while(q--)
	{
		scanf("%i %i %i %i",&y1,&x1,&y2,&x2);
		if(y1==y2){ printf("%i\n",max(x1,x2)-min(x1,x2));continue;}
		i=lower_bound(el.begin(),el.end(),x1)-el.begin();
		//if(i!=el.size() && el[i]<y2){ printf("%i\n",max(x1,x2)-min(x1,x2)+(max(y1,y2)-min(y1,y2)+v-1)/v);continue;}
		int sol=inf;
		if(i!=el.size()) ckmin(sol,dist(x1,el[i])+dist(el[i],x2)+(dist(y1,y2)+v-1)/v);
		if(i!=0) i--,ckmin(sol,dist(x1,el[i])+dist(el[i],x2)+(dist(y1,y2)+v-1)/v);
		i=lower_bound(st.begin(),st.end(),x1)-st.begin();
		if(i!=st.size()) ckmin(sol,dist(x1,st[i])+dist(st[i],x2)+dist(y1,y2));
		if(i!=0) i--,ckmin(sol,dist(x1,st[i])+dist(st[i],x2)+dist(y1,y2));
		printf("%i\n",sol);
	}
	return 0;
}