#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=1000005;
const ll INF=1e18;
string s1,s2;
int main(){
	cin>>s1>>s2;
	if (s1==s2){cout<<-1<<endl;return 0;}
	cout<<max(s1.size(),s2.size())<<endl;
	return 0;
}