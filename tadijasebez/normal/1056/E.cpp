#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int base=37;
const int N=1000050;
int hsh[N],po[N];
int H(int l,int r){return (hsh[r+1]-(ll)hsh[l]*po[r-l+1]%mod+mod)%mod;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;cin>>s>>t;
	if(s[0]=='1')for(int i=0;i<s.size();i++)s[i]=((s[i]-'0')^1)+'0';
    int cnt[2]={0,0};
    for(char c:s)cnt[c-'0']++;
    po[0]=1;
    for(int i=1;i<=t.size();i++)hsh[i]=((ll)hsh[i-1]*base+(t[i-1]-'a'+1))%mod,po[i]=(ll)po[i-1]*base%mod;;
    int ans=0;
    for(int A=1;A<=t.size();A++){
		int len=t.size()-A*cnt[0];
		if(len<0)break;
		if(cnt[1] && len%cnt[1]!=0)continue;
		if(cnt[1] && !len)continue;
		if(!cnt[1] && len)continue;
		int B=cnt[1]?len/cnt[1]:0;
		int l=0,r=-1;
		bool ok=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				if(H(0,A-1)!=H(l,l+A-1))ok=0;
				//for(int j=0;j<A;j++)if(t[l+j]!=t[j])ok=0;
				l+=A;
			}else{
				if(r==-1)r=l;
				if(H(r,r+B-1)!=H(l,l+B-1))ok=0;
				//for(int j=0;j<B;j++)if(t[r+j]!=t[l+j])ok=0;
				l+=B;
			}
		}
		if(A==B){
			//bool ok2=0;
			//for(int j=0;j<A;j++)if(t[j]!=t[r+j])ok2=1;
			//if(!ok2)ok=0;
			if(H(0,A-1)==H(r,r+B-1))ok=0;
		}
		if(ok)ans++;
    }
    cout<<ans<<"\n";
	return 0;
}