#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=250050;
struct CMPR{
	vector<ll> all;
	void Add(ll x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int GetR(ll x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
	int Find(ll x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
}CPR;
int p[N],r[N],x[N],y[N],m[N];
ll d[N];
struct cmp{bool operator()(int i,int j){return m[i]<m[j]||(m[i]==m[j]&&i<j);}};
set<int,cmp> pts[N];
void Add(int idx){for(int i=d[idx];i<N;i+=i&-i)pts[i].insert(idx);}
queue<int> q;
void Get(int P,int R){
	for(int i=CPR.GetR((ll)R*R);i;i-=i&-i){
		while(pts[i].size()&&m[*pts[i].begin()]<=P){
			q.push(*pts[i].begin());
			pts[i].erase(pts[i].begin());
		}
	}
}
ll sq(ll x){return x*x;}
bool was[N];
int main(){
	int X,Y,P,R,n;
	scanf("%i %i %i %i %i",&X,&Y,&P,&R,&n);
	for(int i=1;i<=n;i++){
		scanf("%i %i %i %i %i",&x[i],&y[i],&m[i],&p[i],&r[i]);
		d[i]=sq(x[i]-X)+sq(y[i]-Y);
		CPR.Add(d[i]);
	}
	CPR.Build();
	for(int i=1;i<=n;i++)d[i]=CPR.Find(d[i]),Add(i);
	Get(P,R);
	int ans=0;
	while(q.size()){
		int idx=q.front();
		q.pop();
		if(was[idx])continue;
		was[idx]=1;
		ans++;
		Get(p[idx],r[idx]);
	}
	printf("%i\n",ans);
	return 0;
}