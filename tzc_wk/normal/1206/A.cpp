#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
int n,m,a[105],b[105];
bool p[405];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],p[a[i]]=1;
	cin>>m;
	for(int i=1;i<=m;i++)	cin>>b[i],p[b[i]]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!p[a[i]+b[j]]){
				cout<<a[i]<<" "<<b[j]<<endl;
				return 0;
			}
		}
	}
	return 0;
}