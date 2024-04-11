#include<bits/stdc++.h>
using namespace std;
int s[26],t[100005];
map<int,int>a;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	string str;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		cin>>str;
		for(int i=0;i<str.size();i++)
			s[str[i]-'a']++;
		int k=0;
		for(int i=0;i<26;i++)
			if(s[i]%2)
				k+=(1<<i);
		t[i]=k;
		a[k]++;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a.find(t[i])!=a.end())
			sum+=a[t[i]]-1;
		for(int j=0;j<26;j++)
		{
			int k=t[i];
			if((k>>j)&1==1)
				k-=1<<j;
			else
				k+=1<<j;
			if(a.find(k)!=a.end())
				sum+=a[k];
		}
	}
	cout<<sum/2<<endl;
	return 0;
}