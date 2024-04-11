#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=0;

string s;
int main(){
	cin>>s;
	int n=s.length(),st=0;
	while (st<n&&s[st]=='a') st++;
	if (st==n) s[n-1]='z';
	for(int i=st;i<n;i++){
		if (s[i]=='a') break;
		else s[i]--;
	}
	cout<<s;
}