#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,m,t;
ll n,res,r2,c[300][300],a[300],pre;

struct sb{
	int id;
	string s;
	bool operator<(const sb x)const{
		int i=0;
		for(i=0;;i++){
			if(i&1){
				if(s[i]==x.s[i])continue;
				return s[i]>x.s[i];
			}
			else{
				if(s[i]==x.s[i])continue;
				return s[i]<x.s[i];
			}
		}
	}
}s[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i].s;
		s[i].id=i;
	}
	sort(s+1,s+n+1);
	for(i=1;i<=n;i++){
		cout<<s[i].id<<' ';
	}
}