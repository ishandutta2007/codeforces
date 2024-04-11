#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n=200020;

struct bit{
	int bitc[200020];
	int sum(int i)
	{
		int s=0;
		while(i>0)
		{
			s+=bitc[i];
			i-=(i&(-i));
		}
		return s;
	}
	void add(int i,int x)
	{
		while(i<=n)
		{
			bitc[i]+=x;
			i+=( i & (-i));
		}
	}
};

bit b[30];

bool rem[30][200020];

int main()
{
	int k;
	cin>>k;
	string str;
	cin>>str;
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<200020;j++)
		{
			rem[i][j]=true;
		}
	}
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<200020;j++)
		{
			b[i].bitc[j]=0;
		}
	}
	int sz=str.size();
	int cnt[30];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<sz;i++)
	{
		char ch=str[i];
		cnt[ch-'a']++;
	}
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=cnt[i]*k;j++)
		{
			b[i].add(j,1);
		}
	}
	int change;
	cin>>change;
	for(int i=0;i<change;i++)
	{
		int p;
		string c;
		cin>>p>>c;
		//scanf("%d%s",&p,c);
		
		int cn=c[0]-'a';
		int lb=0,ub=cnt[cn]*k;
		while(ub-lb>1)
		{
			int mid=(lb+ub)/2;
			if(b[cn].sum(mid)<p)
			{
				lb=mid;
			}
			else ub=mid;
		}
		rem[cn][ub]=false;
		b[cn].add(ub,-1);
	}
	int output[30];
	memset(output,0,sizeof(output));
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<sz;j++)
		{
			output[str[j]-'a']++;
			if(rem[str[j]-'a'][output[str[j]-'a']])
			{
				cout<<str[j];
			}
		}
	}
	cout<<"\n";
	return 0;
}