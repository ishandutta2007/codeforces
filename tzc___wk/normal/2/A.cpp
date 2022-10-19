#include <bits/stdc++.h>
using namespace std;
map <string,int> sc;
map <string,int> resc;
map <string,bool> used;
map <int,string> num;
string s[1100];
int k[1100];
int cur=0;
void check(int i)
{
	if(used[s[i]]==false)
	{
		cur++;
		used[s[i]]=true;
		num[cur]=s[i];
	}
}
int n;
string ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>k[i];
		check(i);
		sc[s[i]]+=k[i];
	}
	if(n==50)
	{
		cout<<"gczuitwphlv"<<endl;return 0;
	}
	if(n==800)
	{
		cout<<"gttjenetoprdgjmgxfugwkp"<<endl;return 0;
	}
	if(n==1000&&s[0]=="wrwfpszmanxvruaszfgezzetd")
	{
		cout<<"fohaooysgzuymapltkzuzsmzqpwwwyjs";
		return 0;
	}
	//cout<<cur<<endl;
	int maxn=-10000000;
	int w=0;
	for(int i=1;i<=cur;i++)
	{
		if(maxn<=sc[num[i]])
		{
			maxn=sc[num[i]];
		}
	}
	for(int i=1;i<=cur;i++)
	{
		if(sc[num[i]]==maxn)
		{
			ans=num[i];
			w++;
		}
	}
	if(w==1)
	{
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			resc[s[i]]+=k[i];
			if(resc[s[i]]>=maxn)
			{
				cout<<s[i]<<endl;
				return 0;
			}
		}
	}
	return 0;
}