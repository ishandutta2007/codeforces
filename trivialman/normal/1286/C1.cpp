#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
typedef long long LL;
const LL P = 998244353;
const int N = 105;
mt19937 rng(time(0));

int n,n1,n2,n3;
string ans[N];
string s;
vector<string> a[N], b[N], c[N];

void work(vector<string> a[], int n){
	rep(i,1,n*(n+1)/2){
		cin>>s;
		sort(s.begin(), s.end());
		//cout<<s<<endl; 
		a[s.size()].push_back(s);
	}
	rep(i,1,n){
		sort(a[i].begin(), a[i].end());
	}
}

char find(string s1,string s2){
	int a[200];
	memset(a,0,sizeof a);
	for(auto ch:s1) a[ch]--;
	for(auto ch:s2) a[ch]++;
	rep(ch,0,128) if(a[ch]!=0) return ch;
	return '?';
}

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	n1 = n, n2 = n-1;
	cout<<"? 1 "<<n1<<endl<<flush;
	work(a,n1);
	if(n>1){
		cout<<"? 1 "<<n2<<endl<<flush;
		work(b,n2);
	}
	
	ans[0] = ans[n+1] = "";
	rep(i,1,n){
		b[i].PB("");
		rep(j,0,n-i){
			//cout<<a[i][j]<<" "<<b[i][j]<<endl;
			if(a[i][j]!=b[i][j]){
				ans[i] = a[i][j];
				break;
			}
		}
	}
	//rep(i,1,n)cout<<ans[i]<<endl;
	cout<<"! ";
	rrep(i,n,1)cout<<find(ans[i],ans[i-1]);
	return 0;
}