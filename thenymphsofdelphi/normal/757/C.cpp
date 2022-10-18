#include<iostream>
#include<vector>
#include<algorithm>
#define hash hash1
#define int long long
using namespace std;
const int mod=1e9+7;
const int base=79;
const int base1=29;
const int N=1e6+5;
const int M=1e5+5;
int fact[N],mul[N],mul1[N],hash2[N];
vector<pair<int,int> >  occur[N];
vector<int> lis[M];
pair<int,int> hash[N];
int binpow(int x,int y){
	int tich=1;
	while(y){
		if(y%2==1){
			tich*=x;
			tich%=mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return tich;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,k,l,cnt=0,ans=1;
	cin>>n>>m;
	fact[0]=1;
	mul[0]=1;
	mul1[0]=1;
	for(i=1;i<=1e6;i++){
		fact[i]=(fact[i-1]*i)%mod;
		mul[i]=(mul[i-1]*base)%mod;
		mul1[i]=(mul1[i-1]*base1)%mod;
	}
	for(i=1;i<=n;i++){
		cin>>j;
		for(k=1;k<=j;k++){
			cin>>l;
			lis[i].push_back(l);
		}
		sort(lis[i].begin(),lis[i].end());
		k=0;
		while(k<lis[i].size()){
			l=k;
			while(l<lis[i].size()&&lis[i][k]==lis[i][l]){
				l++;
			}
			occur[lis[i][k]].push_back({i,l-k});
			k=l;
		}
	}
	for(i=1;i<=m;i++){
		for(j=0;j<occur[i].size();j++){
			hash[i].first=(hash[i].first+mul[occur[i][j].first]*occur[i][j].second)%mod;
			hash[i].second=(hash[i].second+mul1[occur[i][j].first]*occur[i][j].second)%mod;
		}
	}
	sort(hash+1,hash+1+m);
	i=1;
	while(i<=m){
		j=i;
		while(j<=m&&hash[i]==hash[j]){
			j++;
		}
		ans=(ans*fact[j-i])%mod;
		i=j;
	}
	cout<<ans;
}