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
using namespace std;
ll n;
map<ll,int> mp1;
map<ll,string> mp2;
string TOS(ll n){
	string ans;
	for (;n;ans=char('0'+n%10)+ans,n/=10);
	return ans;
}
int main(){
	scanf("%lld",&n);
	string ans=TOS(n);
	if (n==10000000000ll)
		return puts("10^10\n"),0;
	for (int i=2;1ll*i*i<=n;i++)
		for (ll j=1ll*i*i,k=2;j<=n;j*=i,k++){
			string tmp=TOS(i)+"^"+TOS(k);
			//if (i==5&&k==9) cout<<n/j<<' '<<TOS(n/j)<<' '<<mp2[n/j]<<endl;
			int len=tmp.length();
			if (!mp1[j]||mp1[j]>len) mp1[j]=len,mp2[j]=tmp;
			For(T,2,9){
				if (j+T<=n&&(!mp1[j+T]||mp1[j+T]>len+2))
					mp1[j+T]=len+2,mp2[j+T]=tmp+"+"+char('0'+T);
				if (j*T<=n&&(!mp1[j*T]||mp1[j*T]>len+2))
					mp1[j*T]=len+2,mp2[j*T]=tmp+"*"+char('0'+T);
			}
		}
	//cout<<mp2[1<<20]<<endl;
	for (int i=2;1ll*i*i<=n;i++)
		for (ll j=1ll*i*i,k=2;j<=n;j*=i,k++){
			string tmp=TOS(i)+"^"+TOS(k);
			if (j==n&&tmp.length()<ans.length()) ans=tmp;
			if (tmp.length()+1+TOS(n-j).length()<ans.length())
				ans=tmp+"+"+TOS(n-j);
			if (mp1[n-j]&&tmp.length()+1+mp1[n-j]<ans.length())
				ans=tmp+"+"+mp2[n-j];
			//if (i==5&&k==9) cout<<ans<<endl;
			if (n%j==0&&tmp.length()+1+TOS(n/j).length()<ans.length())
				ans=tmp+"*"+TOS(n/j);
			//if (i==5&&k==9) cout<<ans<<' '<<mp2[n/j]<<endl;
			if (mp1[n/j]&&n%j==0&&tmp.length()+1+mp1[n/j]<ans.length())
				ans=tmp+"*"+mp2[n/j];
			if (tmp.length()+1+TOS(n/j).length()+1+TOS(n%j).length()<ans.length())
				ans=tmp+"*"+TOS(n/j)+"+"+TOS(n%j);
			if (mp1[n/j]&&tmp.length()+1+mp1[n/j]+1+TOS(n%j).length()<ans.length())
				ans=tmp+"*"+mp2[n/j]+"+"+TOS(n%j);
			//if (i==5&&k==9) cout<<ans<<endl;
		}
	cout<<ans<<endl;
}