#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll t, n ,m;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;
  while(t--){
  	cin >> n;
  	string s;
  	cin >> s;
  	if(s[0]!='9'){
  		rep(i,0,sz(s)-1){
  			cout << ('9'-s[i]);
  		}
  		cout << nl;
  	}
  	else{
  		if(n<8){
  			int pten=1;
  			int m=0;
  			rep(i,0,n){
  				m+=pten;
  				pten*=10;
  			}
  			cout << m-stoi(s) << nl;
  		}
  		else{
  			// 11111
  			int carry=0;
  			string ans="";
  			for(int i=n-1; i>=0; i--){
  				int d=s[i]-'0';
  				d+=carry;
  				ans+=static_cast<char>('0'+(11-d)%10);
  				if(d>1) carry=1;
  				else carry=0;
  			}
  			reverse(all(ans));
  			cout << ans << nl;
  		}
  	}
  }
}