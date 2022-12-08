#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3fll; 
const int D = 60; 

int n; 
ll a[200000]; 
ll t[D]; 
ll sum[D]; 
ll tr[D]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%lld", &a[i] ); 
	t[0] = 1; 
	for (int i = 1; i < D; ++i) 
		t[i] = t[i-1] * 2; 
	for (int i = 1; i <= n; ++i) {
		bool flag = false; 
		for (int j = 0; j < D; ++j) 
			if (a[i] == t[j]) {
				sum[j]++; 
				flag = true; 
				break; 
			}
		if (!flag) {
			for (int j = 0; j < D; ++j) 
				if (t[j] < a[i]) tr[j]--; 
		}
	}
	vi q; 
	//for (int i = 0; i < D; ++i) cout<<t[i]<<'-'<<sum[i]<<' '; puts( "" ); 
	q.clear(); 
	while (sum[0] > 0) {
		//cout<<q.size()<<endl; 
		int i; 
		for (i = 0; sum[i] > 0; ++i) sum[i]--; 
		for (int j = 0; j < i; ++j) tr[j]++; 
		q.pb(i); 
		//cout<<i<<endl; 
	}	
	//cout<<"?"<<endl; 
	for (int i = 0; i < D; ++i) 
		if (sum[i] > 0) {
			//puts( "-1" ); 
			//return 0; 
			//for (int j = 1; j <= sum[i]; ++j) 
			for (int j = 0; j < i; ++j) tr[j] -= sum[i]; 
		}
	vi ans;
	ans.clear(); 
	while (1) {
		//cout<<q.size()<<endl; 
		bool flag = true; 
		//for (int i = 0; i < D; ++i) cout<<tr[i]<<' '; 
		//puts( "" ); 
		for (int i = 0; i < D; ++i) 
			if (tr[i] < 0) {
				flag = false; 
				break; 
			}
		if (flag) ans.pb((int)q.size()); 
		else break; 
		for (int j = 0; j < q.back(); ++j) tr[j] -= q.back()-j; 
		tr[0]--; 
		q.pop_back(); 
	}
	reverse(ans.begin(), ans.end()); 
	for (auto i : ans) printf( "%d ", i ); 
	if (ans.empty()) cout<<-1; 
	puts( "" ); 
}