#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
ll o[SZ],a[SZ],xo[SZ],v[SZ];
int main()
{
	int n,k;
	cin>>n>>k;
//	for(int i=1;i<=n;++i) cin>>v[i];
	for(int i=1;i<n;++i) {
		int j=i+1;
		cout<<"or "<<i<<" "<<j<<endl;
//		o[j]=v[i]|v[j];
		cin>>o[j];
		cout<<"and "<<i<<" "<<j<<endl;
//		a[j]=v[i]&v[j];
		cin>>a[j];
	}
	{
	cout<<"or "<<1<<" "<<3<<endl;
//		o[0]=v[1]|v[3];
	cin>>o[0];
	cout<<"and "<<1<<" "<<3<<endl;
//		a[0]=v[1]&v[3];
	cin>>a[0];
	}
	for(int i=0;i<40;++i) {
		ll x=1LL<<i;
		if(!((o[0]^a[0])&x)) {
			xo[1]^=o[0]&x;
		}
		else if(!((o[2]^a[2])&x)) {
			xo[1]^=o[2]&x;
		}
		else if(!((o[3]^a[3])&x)) {
//			cerr<<"wow\n";
			xo[1]^=(o[3]^o[2]^a[2])&x;
		}
		else assert(0);
	}
	for(int j=2;j<=n;++j)
		xo[j]=xo[j-1]^o[j]^a[j];
//	for(int j=1;j<=n;++j)
//		cerr<<xo[j]<<",";
//	cerr<<"\n";
	sort(xo+1,xo+1+n);
	cout<<"finish "<<xo[k]<<endl;
}