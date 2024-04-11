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
	string s;
	cin>>s;
	string a="",b="",t="";
	int f=1;
	for(int i=0;i<s.size();i++)
	{
		
		if(s[i]==','||s[i]==';') 
		{
			if(f==0||(t[0]=='0'&&t.size()>1)||t.size()==0)
			{
			    //if(i==s.size()-1) cout<<"YASS"<<" "<<b<<endl;
				b+=','+t;
				//if(i==s.size()-1) cout<<"YASS"<<" "<<b<<endl;
				f=1;
			}
			else a+=','+t;
		//	cout<<t<<endl;
			t.clear();
			
		}
		else
		{
			t+=s[i];
			if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9')
			{
				f=0;
			}
		}
		//cout<<t<<" "<<f<<endl;
	}
            if(f==0||(t[0]=='0'&&t.size()>1)||t.size()==0)
			{
			    
				b+=','+t;
				f=1;
			}
			else a+=','+t;
	if(a.size()) cout<<'"'<<a.substr(1,a.size()-1)<<'"'<<"\n";
	else cout<<'-'<<"\n";
	if(b.size()) cout<<'"'<<b.substr(1,b.size()-1)<<'"'<<"\n";
	else cout<<'-'<<"\n";
}