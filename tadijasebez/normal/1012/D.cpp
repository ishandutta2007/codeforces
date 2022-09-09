#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
vector<pair<int,int> > sol;
bool fir=1;
void Try(string s, string t, bool push, pair<int,int> p)
{
	int n=s.size(),m=t.size(),i,j,h,a,b;
	for(h=0;h<=1;h++)
	{
		vector<pair<int,int> > ans;
		if(push) ans.pb(p);
		i=0,j=0;
		a=0,b=0;
		while(i<n || j<m)
		{
			if(i<n) s[i]=='a'?a++:b++;
			while(i+1<n && s[i]==s[i+1]) i++,s[i]=='a'?a++:b++;
			if(j<m) t[j]=='a'?a++:b++;
			while(j+1<m && t[j]==t[j+1]) j++,t[j]=='a'?a++:b++;
			if(i>=n-1 && j>=m-1) break;
			if(i<n && j<m && s[i]==t[j])
			{
				if(h==0)
				{
					ans.pb(mp(i+1,0));
					if(t[j]=='a') a--;
					else b--;
					i++;
				}
				else
				{
					ans.pb(mp(0,j+1));
					if(s[i]=='a') a--;
					else b--;
					j++;
				}
			}
			else
			{
				if((i<n && s[i]=='a') || (j<m && t[j]=='b')) ans.pb(mp(a,b));
				else ans.pb(mp(b,a));
				i++;j++;
			}
		}
		if(fir || sol.size()>ans.size()) sol=ans,fir=0;
	}
}
int main()
{
	string s,t;
	cin >> s >> t;
	//Try(s,t,0,mp(0,0));
	int i;
	vector<int> x,y;
	for(i=0;i+1<s.size();i++) if(s[i]!=s[i+1]) x.pb(i);
	for(i=0;i+1<t.size();i++) if(t[i]!=t[i+1]) y.pb(i);
	bool sw=0;
	if(x.size()<y.size()) swap(x,y),swap(s,t),sw=1;
	if(x.size()>y.size())
	{
		int mid=x.size()+y.size();
		mid/=2;
		for(i=max(0,mid-8);i<min((int)x.size(),mid+8);i++)
		{
			int h=x[(int)x.size()-i-1];
			string a,b;
			a=s.substr(h+1,s.size()-h-1);
			b=s.substr(0,h+1)+t;
			//cout << a << " " << b << "\n";
			if(!sw) Try(a,b,1,mp(h+1,0));
			else Try(b,a,1,mp(0,h+1));
			int k;
			if(y.size()) k=y[0];
			else k=t.size()-1;
			string c,d;
			a=t.substr(0,k+1)+s.substr(h+1,s.size()-h-1);
			b=s.substr(0,h+1)+t.substr(k+1,t.size()-k-1);
			//cout << a << " " << b << "\n";
			if(!sw) Try(a,b,1,mp(h+1,k+1));
			else Try(b,a,1,mp(k+1,h+1));
		}
	}
	if(!sw) Try(s,t,0,mp(0,0));
	else Try(t,s,0,mp(0,0));
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}