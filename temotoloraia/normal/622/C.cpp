#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,a[200005];
set<pair<int,int> >S[1000005];
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ind=1;
	for (int i=1;i<=n;i++)
		if (a[i+1]!=a[ind]){
			S[a[ind]].insert(mp(ind,i));
			ind=i+1;
		}
	while (m--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if (S[x].size()==0){
			cout<<l<<endl;
			continue;
		}
		set<pair<int,int> >::iterator I=S[x].upper_bound(mp(l,n));
		if (I==S[x].begin()){
			cout<<l<<endl;
			continue;
		}
		I--;
		if ((*I).sc>=r){
			cout<<-1<<endl;
			continue;
		}
		if ((*I).sc+1>=l)
		cout<<(*I).sc+1<<endl;
		else
		cout<<l<<endl;
	}
    return 0;
}