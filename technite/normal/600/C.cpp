#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int main()
{
	int ch[26]={0};
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	{
		ch[s[i]-'a']++;
	}
	int c=0;
	for(int i=0;i<26;i++)
	{
		if(ch[i]%2) c++;
	}
//	cout<<c<<'d'<<c/2<<endl;
	if(n%2==0)
	{
		int coun=0;
		for(int i=0;i<26;i++)
		{
			if(ch[i]%2&&coun<c/2)
			{
				ch[i]++;
				coun++;
			}
			else if(ch[i]%2) ch[i]--;
		}
		string a="";
		for(int i=0;i<26;i++)
		{
			a+=string(ch[i]/2,(char)(i+'a'));
		}
		string ans=a;
		//cout<<"yess";
		//cout<<a<<endl;
		reverse(a.begin(),a.end());
		//cout<<a<<endl;
		ans+=a;
		cout<<ans;
	}
	else
	{
		int coun=0;
		for(int i=0;i<26;i++)
		{
		    //cout<<ch[i]<<" "<<coun<<endl;
			if(ch[i]%2&&coun==c/2) coun++;
			else if(ch[i]%2&&coun<c/2)
			{
				ch[i]++;
				coun++;
			}
			else if(ch[i]%2&&coun>c/2) ch[i]--;
			//cout<<ch[i]<<" "<<coun<<endl;
		}
		string a="",b="";
		for(int i=0;i<26;i++)
		{
		   // cout<<ch[i]<<endl;
			if(ch[i]%2) {a+=(char)(i+'a');b+=string((ch[i]-1)/2,(char)(i+'a'));}
			else b+=string(ch[i]/2,(char)(i+'a'));
			//cout<<a<<" "<<b<<endl;
		}
		string ans=b+a;
		reverse(b.begin(),b.end());
		ans+=b;
		cout<<ans;
	}

}