#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(),v.end()
using namespace std;
string ss="abacaba";
string s;
int n;
bool mat(string s,int p){
	For(i,0,6)
		if (s[i+p]!=ss[i]&&s[i+p]!='?')
			return 0;
	return 1;
}
void solve(){
	cin>>n>>s;
	For(i,0,n-7){
		string t=s;
		if (!mat(s,i)) continue;
		//cout<<i<<endl;
		For(j,0,6) t[i+j]=ss[j];
		For(j,0,n-1) if (t[j]=='?') t[j]='z';
		int flg=0;
		For(j,0,n-7) if (mat(t,j)!=(j==i)) flg=1;
		if (flg==1) continue;
		cout<<"Yes\n"<<t<<endl;
		return;
	}
	cout<<"No\n";
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}