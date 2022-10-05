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
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
int n;
pair<int,int> a[105]; 
int main(){
	cin>>n;
	REP(i,n)	cin>>a[i].first,a[i].second=i;
	sort(a+2,a+n+1);
	int sum=0;
	REP(i,n)	sum+=a[i].first;
	vector<int> v;
	v.push_back(1);
	int sum2=0;
	for(int i=2;i<=n;i++){
		if(2*a[i].first>a[1].first)	break;
		sum2+=a[i].first;
		v.push_back(a[i].second);
	}
	if(sum2+a[1].first<=sum/2)	puts("0");
	else{
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)	cout<<v[i]<<" ";
	}
	return 0;
}