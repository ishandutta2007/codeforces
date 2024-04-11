#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T,n,ans;
int n0[N],b[20];
char s[N];
priority_queue<ar2,vector<ar2>,greater<ar2>> Q, Q1;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d\n",&T);
	while(T--){
		while(!Q.empty())Q.pop();
		scanf("%s",s+1);
		n = strlen(s+1);
		n0[0] = ans = 0;
		rep(i,1,n) n0[i]=s[i]=='0'?n0[i-1]+1:0;
		rep(i,1,n) if(s[i]=='1')Q.push({n0[i-1],i});
		
		rep(i,1,n){
			int x=i,m=0;
			while(x){
				b[++m]=x%2;
				x/=2;
			}
			reverse(b+1,b+m+1);
			while(!Q.empty() && Q.top()[0]<i-m) Q.pop();
			//cout<<i<<" ??? "<<Q.size()<<endl;
			Q1 = Q;
			while(!Q1.empty()){
				int j = Q1.top()[1];
				Q1.pop();
				if(j+m-1>n) continue; 
				bool flag = true;
				rep(k,1,m) if(s[j+k-1]-48!=b[k]) flag = false;
				if(flag) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}