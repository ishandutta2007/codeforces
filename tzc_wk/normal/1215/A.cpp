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
int a1,a2,k1,k2,n,ans1,ans2;
int main(){
	cin>>a1>>a2>>k1>>k2>>n;
	int x1=n/k1,x2=n/k2;
	int ans=0;
	if(k1<k2){
		if(x1<=a1)	ans2=x1;
		else		ans2=(n-k1*a1)/k2+a1;
	}
	else if(k2<k1){
		if(x2<=a2)	ans2=x2;
		else		ans2=(n-k2*a2)/k1+a2;
	}
	else	ans2=n/k1;
	if(n<=a1*(k1-1)+a2*(k2-1))	ans1=0;
	else						ans1=n-(a1*(k1-1)+a2*(k2-1));
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}