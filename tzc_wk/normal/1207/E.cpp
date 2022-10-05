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
vector<int> v;
int x,y;
int main(){
	srand(time(0));
	cout<<"? ";
	for(int i=1;i<128;i++){
		v.push_back(i*128);
	}
	random_shuffle(v.begin(),v.end());
	for(int i=0;i<100;i++){
		if(v[i])
			cout<<v[i]<<((i==99)?'\n':' ');
	}
	fflush(stdout);
	cin>>x;
	v.clear();
	cout<<"? ";
	for(int i=0;i<128;i++){
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());
	for(int i=0;i<100;i++){
		cout<<v[i]<<((i==99)?'\n':' ');
	}
	fflush(stdout);
	cin>>y;
	for(int i=0;i<14;i++){
		int dig1=(x>>i)&1,dig2=(y>>i)&1;
		if(dig1!=dig2){
			if(i<7){
				y^=(1<<i);
			}
			else{
				x^=(1<<i);
			}
		}
	}
	cout<<"! "<<x<<endl;
	fflush(stdout);
	return 0;
}