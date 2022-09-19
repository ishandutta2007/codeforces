#include <bits/stdc++.h> 

using namespace std;
#define int long long 
const int maxn=5e5+5;
int fe[maxn][3];int sz;
void pl(int pos,int val,int id) {while(pos<sz) {fe[pos][id]+=val;pos|=(pos+1);}} 
int get(int pos,int id) {int ans=0;while(pos>=0) {ans+=fe[pos][id];pos&=(pos+1);--pos;} return ans;}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;string s;cin>>s;sz=(2*n+2);int sz1=sz/2;for(int i=0;i<sz;++i) for(int j=0;j<3;++j) fe[i][j]=0;
		int pr[n+1];pr[0]=0;for(int i=0;i<n;++i) {if(s[i]=='+') pr[i+1]=pr[i]+1; else pr[i+1]=pr[i]-1;} //for(int i=0;i<n;++i) cout<<pr[i]<<' ';
		int ans=0;for(int i=n;i>=0;--i) {ans+=get(pr[i]+sz1,(pr[i]%3+3)%3);pl(pr[i]+sz1,1,(pr[i]%3+3)%3);} cout<<ans<<'\n';
	}
	return 0;
}