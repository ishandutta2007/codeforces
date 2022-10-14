// Author : WangZhikun
// Date   : 2018.08.03

#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll gmin(ll a,ll b){return a<b?a:b;}
ll gmax(ll a,ll b){return a>b?a:b;}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x,ll &y){ll d = a;if(b!=0){d = exgcd(b,a%b,y,x);y-=(a/b)*x;}else{x = 1; y = 0;}return d;}
ll inv(ll a){ll d,x,y;d = exgcd(a,mod,x,y);return d==1 ? (x+mod)%mod : -1;}

ll n,m,a[110],b[110],aa[110],bb[110],ans[110][110],aans[110][110],ok = 1;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=0;j<m;j++)cin>>b[j];
	for(int MD = 0;MD<30;MD++){
		memset(aans, 0, sizeof(aans));
		int cnt1 = 0,cnt2 = 0;
		for(int i=0;i<n;i++){
			aa[i] = ((a[i]&(1<<MD))!=0);
			//cout<<aa[i]<<' ';
			cnt1+=aa[i];
		}
		//cout<<endl;
		for(int j=0;j<m;j++){
			bb[j] = ((b[j]&(1<<MD))!=0);
			cnt2+=bb[j];
			//cout<<bb[j]<<' ';
		}
		//cout<<endl;
		if(cnt1%2 != cnt2%2)ok=0;
		for(int i=0;i<n;i++){
			if(aa[i]){
				aans[i][0] = 1-aans[i][0];
				bb[0] = !bb[0];
			}
		}
		for(int i=0;i<m;i++){
			if(bb[i])aans[0][i] = 1-aans[0][i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(aans[i][j])ans[i][j]+=(1<<MD);
				//cout<<ans[i][j];
			}
			//cout<<endl;
		}
	}
	if(ok){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}