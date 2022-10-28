#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	//cin.exceptions(cin.failbit);
	int n,m,c;cin>>n>>m>>c;
	int a[n] = {0};
	rep(i,m){
		int x;cin>>x;
		if(x>c/2){
			//cout<<x<<endl;
			int st = n-1;
			while(a[st]>=x) st--;
			cout<<st+1<<endl;
			a[st] = x;
		}
		else{
			int st = 0;
			while(a[st]<=x&&a[st]!=0) st++;
			cout<<st+1<<endl;
			a[st]=x;
		}
		bool flag = false;
		rep(i,n-1){
			if(a[i]>a[i+1]||a[i]==0) flag =true;
		}
		if(flag||a[n-1]==0) continue;
		return 0;
	}


	return 0;
}