#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pt pair<ll,ll>
#define x first
#define y second
#define pb push_back
#define ldb double
ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
pt operator -(pt a,pt b){return (pt){a.x-b.x,a.y-b.y};}
ll cross(pt a,pt b,pt c){return cross(b-a,c-a);}
vector<pt> hull;
bool operator <(pt a,pt b){return a.x*b.y<b.x*a.y;}
const int N=1000050;
ll a[N];
int my[N];
pt Get(int i,int j){return {a[j]-a[i-1],j-i+1};}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=n,sz=0;i>=1;i--){
		while(sz>=2 && cross((pt){(ll)i,a[i]},hull[sz-2],hull[sz-1])>0)sz--,hull.pop_back();
		hull.pb((pt){(ll)i,a[i]});sz++;
		int top=sz-2,bot=0,mid,ans=sz-1;
		while(top>=bot){
			mid=top+bot>>1;
			if(Get(i,hull[mid].first)<Get(i,hull[mid+1].first))ans=mid,top=mid-1;
			else bot=mid+1;
		}
		my[i]=hull[ans].first;
	}
	for(int i=1;i<=n;i=my[i]+1){
		ldb now=a[my[i]]-a[i-1];
		now/=my[i]-i+1;
		for(int j=i;j<=my[i];j++)
			printf("%.10f\n",now);
	}
	return 0;
}