#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 105;
mt19937 rng(time(0));

int n,n1,n2,n3;
string ans[N];
string s;
vs a[N], b[N], c[N];

void work(vs a[], int n){
	rep(i,1,n*(n+1)/2){
		cin>>s;
		sort(s.begin(), s.end());
		a[s.size()].push_back(s);
	}
	rep(i,1,n) sort(a[i].begin(), a[i].end());
}

string diff(string s1,string s2){
	int a[200];
	memset(a,0,sizeof a);
	string res;
	for(auto ch:s1) a[ch]++;
	for(auto ch:s2) a[ch]--;
	rep(ch,0,128) rep(i,1,abs(a[ch])) res += ch;
	return res;
}

string solve(vs a[], vs b[], int n){
	ans[0] = ans[n+1] = "";
	rep(i,1,n){
		b[i].PB("");
		rep(j,0,n-i){
			if(a[i][j]!=b[i][j]){
				ans[i] = a[i][j];
				break;
			}
		}
	}
	string res = "";
	rrep(i,n,1) res += diff(ans[i],ans[i-1]);
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	n1 = (n+1)/2, n2 = n1-1;
	cout<<"? 1 "<<n1<<endl<<flush;
	work(a,n1);
	if(n2){
		cout<<"? 1 "<<n2<<endl<<flush;
		work(b,n2);
	}
	
	string left = solve(a,b,n1), right, whole;
	//cout<<left<<endl;
	cout<<"? 1 "<<n<<endl<<flush;
	work(a,n);
	whole = a[n][0];
	
	rrep(i,n,n1+1){
		vs shao, duo;
		rep(j,0,n-i){
			string s = left.substr(0,n-i+1-j) + right.substr(n-i-j);
			sort(s.begin(),s.end());
			shao.PB(s);
		}
		sort(shao.begin(), shao.end());
		
		for(auto x:a[i-1]){
			string s = diff(whole, x);
			sort(s.begin(),s.end());
			duo.PB(s);
		}
		sort(duo.begin(), duo.end());
		shao.PB("");
		rep(j,0,n-i+1){
			//cout<<shao[j]<<" "<<duo[j]<<endl;
			if(duo[j]!=shao[j]){
				right = diff(duo[j], right) +right;
				break;
			}
		}
	}
	cout<<"! "+left+right<<endl;
	return 0;
}