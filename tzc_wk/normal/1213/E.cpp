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
string s,t;
const string perm[]={"abc","acb","bac","bca","cab","cba"};
int main(){
	cin>>n>>s>>t;
	for(int i=0;i<6;i++){
		bool flag=1;
		for(int j=0;j<=2;j++){
			if(perm[i][j]==s[0]&&perm[i][(j+1)%3]==s[1])	flag=0;
			if(perm[i][j]==t[0]&&perm[i][(j+1)%3]==t[1])	flag=0;
		}
		if(flag){
			puts("YES");
			for(int j=1;j<=n;j++)	cout<<perm[i];
			return 0;
		}
	}
	for(int i=0;i<6;i++){
		bool flag=1;
		for(int j=0;j<3;j++){
			if(s[0]==s[1]&&perm[i][j]==s[0])	flag=0;
			if(t[0]==t[1]&&perm[i][j]==t[0])	flag=0;
		}
		for(int j=0;j<2;j++){
			if(perm[i][j]==s[0]&&perm[i][j+1]==s[1])	flag=0;
			if(perm[i][j]==t[0]&&perm[i][j+1]==t[1])	flag=0;
		}
		if(flag){
			puts("YES");
			for(int j=1;j<=n;j++)	putchar(perm[i][0]);
			for(int j=1;j<=n;j++)	putchar(perm[i][1]);
			for(int j=1;j<=n;j++)	putchar(perm[i][2]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}