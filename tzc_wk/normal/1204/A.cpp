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
string k;
int main(){
	cin>>k;
	if(k=="0")	puts("0");
	else{
		for(int i=0;i<=50;i++){
			string s="1";
			for(int j=0;j<2*i;j++)	s+="0";
//			cout<<s<<endl;
			if(s.size()>k.size()||s>=k){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}