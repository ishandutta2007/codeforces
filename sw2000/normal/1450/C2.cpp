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
			if(boa[i][j]=='X'||boa[i][j]=='O'){
				cnt[(i+j)%3]++;
			}
		}
	}
	int a,b;
	if(cnt[0]>=cnt[1]&&cnt[0]>=cnt[2])a=2,b=1;
	if(cnt[1]>=cnt[0]&&cnt[1]>=cnt[2])a=2,b=0;
	if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[0])a=0,b=1;
	
	int c1=0,c2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(boa[i][j]=='X'&&(i+j)%3==a||boa[i][j]=='O'&&(i+j)%3==b){
				c1++;
			}else if(boa[i][j]=='O'&&(i+j)%3==a||boa[i][j]=='X'&&(i+j)%3==b){
				c2++;
			}
		}
	}
	if(c1<c2){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(boa[i][j]=='X'&&(i+j)%3==a){
				cout<<'O';
			}else if(boa[i][j]=='O'&&(i+j)%3==b){
				cout<<'X';
			}
			else cout<<boa[i][j];
		}
		cout<<endl;
	}
	}else{
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(boa[i][j]=='O'&&(i+j)%3==a){
				cout<<'X';
			}else if(boa[i][j]=='X'&&(i+j)%3==b){
				cout<<'O';
			}else cout<<boa[i][j];
		}
		cout<<endl;
	}
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