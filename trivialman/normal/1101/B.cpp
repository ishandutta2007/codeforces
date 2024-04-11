#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 5e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[N];
int n;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%s",s+1);
	n = strlen(s+1);
	int i=1,j=n,t1=0,t2=0;
	for(;i<=j;++i){
		if(s[i]=='[' && t1==0) ++t1;
		if(s[i]==':' && t1==1) break;
	}
	for(;j>=i;--j){
		if(s[j]==']' && t2==0) ++t2;
		if(s[j]==':' && t2==1) break;
	}
	//cout<<i<<" "<<j<<endl;
	if(i>=j){
		cout<<"-1\n";
		return 0;
	}
	int ans = 4;
	rep(k,i+1,j-1) ans += (s[k]=='|');
	cout<<ans<<endl;
	return 0;
}