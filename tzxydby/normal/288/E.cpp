#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long f,s1,s2,a1,a2,k,ans;
string s;
long long sol()
{
	cin>>s;
	f=s1=s2=a1=a2=0,k=1;
	for(int i=0;i<s.size();i++)
	{
		f=(100*f+100*s1+220*s2+70*(a2+mod-a1)%mod+56*(k-1))%mod;
		s1=(200*s1+220*s2+65*(k-1))%mod;
		s2=(20*s2+11*(k-1))%mod;
		if(s[i]=='7')
		{
			f=(f+((a2*10+4)%mod)*((a2*10+7)%mod))%mod;
			s1=(s1+((a2*10+4)%mod)*((a2*10+4)%mod))%mod;
			s2=(s2+a2*10+4)%mod;
		}
		a2=(a2*10+s[i]-'0')%mod;
		a1=(a1*10+4)%mod;
		k=((k-1)*2+((s[i]=='4')?1:2))%mod;
	}
	return f;
}
int main()
{
	ios::sync_with_stdio(false);
	ans-=sol();
	ans+=sol();
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}