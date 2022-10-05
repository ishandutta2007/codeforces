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
int n;
char s[200005],t[200005];
vector<int> v1,v2;
int main(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='a'&&t[i]=='b')		v1.push_back(i);
		else if(s[i]=='b'&&t[i]=='a')	v2.push_back(i);
	}
	if((v1.size()+v2.size())%2)	return puts("-1"),0;
	cout<<(v1.size()+1)/2+(v2.size()+1)/2<<endl;
	for(int i=0;i<v1.size()/2;i++){
		cout<<v1[i*2]<<" "<<v1[i*2+1]<<endl;
	}
	for(int i=0;i<v2.size()/2;i++){
		cout<<v2[i*2]<<" "<<v2[i*2+1]<<endl;
	}
	if(v1.size()%2){
		cout<<v1.back()<<" "<<v1.back()<<endl;
		cout<<v1.back()<<" "<<v2.back()<<endl;
	}
	return 0;
}