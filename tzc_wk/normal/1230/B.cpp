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
int n,k,a[200005];
int main(){
	scanf("%d%d",&n,&k);
	REP(i,n)	scanf("%1d",a+i);
	if(n==1){
		if(k)	cout<<0<<endl;
		else	cout<<a[1]<<endl;
		return 0;
	}
	if(k){
		if(a[1]!=1){
			a[1]=1;k--;
		}
		for(int i=2;i<=n;i++){
			if(a[i]>0){
				if(k){
					k--;a[i]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)	cout<<a[i];
	return 0;
}