#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[N];
int n,k;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	scanf("%s",s+1);
	int ans = 0;
	for(char ch='a';ch<='z';++ch){
		int cnt = 0;
		for(int i=1,j=1;j<=n;i=j){
			if(s[i]!=ch){
				j=++i; continue;
			}
			
			for(j=i+1;j<i+k && j<=n && s[j]==s[i];++j);
			if(j==i+k) cnt++;
		}
		//cout<<ch<<" "<<cnt<<endl;
		ans = max(ans, cnt);
	}
	cout<<ans<<endl;
	return 0;
}