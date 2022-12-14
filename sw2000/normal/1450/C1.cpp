#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 500 + 10;
const ll mod = 1e9 + 7;

int n;
char boa[N][N];
int solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>boa[i]+1;
	}
	int cnt[3]{};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(boa[i][j]=='X'){
				cnt[(i+j)%3]++;
			}
		}
	}
	int id=0;
	for(int i=0;i<3;i++){
		if(cnt[i]<=(cnt[0]+cnt[1]+cnt[2])/3)
		id=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(boa[i][j]=='X'&&(i+j)%3==id){
				cout<<'O';
			}
			else{
				cout<<boa[i][j];
			}
		}
		cout<<endl;
	}
	
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	int _;cin>>_;
	while(_--)
		solve();
	return 0;
}