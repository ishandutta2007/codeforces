#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define fi first
#define se second
#define PB push_back
#define uint unsigned
using namespace std;
const int mo=998244353;
map<char,int> mpc;
map<string,bool> mp;
int S[66][66][66];
int cnt[66][66][66];
int nd,n;
int solve(int len){
	int ans=0;
	memset(S,0,sizeof(S));
	For(C,1,nd) For(i,1,nd) For(j,i,nd) For(k,j,nd)
		S[i][j][k]=(S[i][j][k]+1ll*cnt[len][C][i]*cnt[len][C][j]%mo*cnt[len][C][k])%mo;
	For(i,1,nd) For(j,i,nd) For(k,j,nd) For(l,k,nd){
		int ways=1ll*S[i][j][k]*S[i][j][l]%mo;
		ways=1ll*ways*S[i][k][l]%mo*S[j][k][l]%mo;
		int times=24;
		times/=(1+(i==j)+(i==k)+(i==l));
		times/=(1+(j==k)+(j==l));
		times/=(1+(k==l));
		ans=(ans+1ll*times*ways)%mo;
	}
	return ans;
}
int main(){
	For(i,'0','9') mpc[i]=++nd;
	For(i,'A','Z') mpc[i]=++nd;
	For(i,'a','z') mpc[i]=++nd;
	scanf("%d",&n);
	For(i,1,n){
		string s,t;
		cin>>s; t=s;
		reverse(t.begin(),t.end());
		int st=mpc[s[0]],ed=mpc[s.back()];
		int len=s.size();
		if (!mp[s]){
			mp[s]=1;
			++cnt[len][st][ed];
		}
		if (!mp[t]){
			mp[t]=1;
			++cnt[len][ed][st];
		}
	}
	int ans=0;
	For(i,3,11) ans=(ans+solve(i))%mo;
	printf("%d\n",ans);
}