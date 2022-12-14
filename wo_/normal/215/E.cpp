#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> divs[64];
long long nums[64]={};//not periodic string that length i
long long all[64]={};//periodic string that length i

long long c[64]={};

long long getper(long long num,int dig,int per)
{
	return (num>>(dig-per));
}

bool check(long long num,int dig,int per)
{
	long long p=getper(num,dig,per);
	long long a=p;
	for(int i=1;i<dig/per;i++)
	{
		a<<=per;
		a+=p;
	}
	return a<=num;
}

long long func(long long l,int d,int p)
{
	//[1<<(d-1),l],period p,not necessarily longest
	long long a=getper(l,d,p);
	a-=(1ll<<(p-1));
	a++;
	if(check(l,d,p)==false) a--;
	return a;
}

long long get(long long l)
{
	if(l==0) return 0;
	//how many periodics in [1,l]
	long long L=l;
	int d=0;
	while(L!=0)
	{
		L>>=1;
		d++;
	}
	for(int i=0;i<64;i++) c[i]=0;
	long long res=0;
	for(int i=0;i<d;i++) res+=all[i];
	for(int i=0;i<divs[d].size();i++)
	{
		long long tmp=0;
		/*
		long long a=getper(l,d,divs[d][i]);
		long long tmp=0;
		a-=(1ll<<(divs[d][i]-1));
		a++;
		tmp+=a;
		if(check(l,d,divs[d][i])==false) tmp--;*/
		tmp+=func(l,d,divs[d][i]);
		for(int j=0;j<divs[divs[d][i]].size();j++)
		{
			/*
			int dd=divs[divs[d][i]][j];
			long long a=getper(l,d,dd);
			a-=(1ll<<(dd-1));
			a++;
			tmp-=a;
			if(check(l,d,dd)==false) tmp++;*/
			//tmp-=func(l,d,divs[divs[d][i]][j]);
			tmp-=c[divs[divs[d][i]][j]];
		}
		c[divs[d][i]]=tmp;
		res+=tmp;
	}
	return res;
}

int main()
{
	for(int i=1;i<64;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i%j==0) divs[i].push_back(j);
		}
	}
	nums[1]=1;
	for(int i=2;i<64;i++)
	{
		long long res=0;
		res+=(1ll<<(i-1));
		for(int j=0;j<divs[i].size();j++)
		{
			//res+=(1ll<<(divs[i][j]-1));
			//for(int k=0;k<divs[j].size();k++)
			//{
			//	res-=nums[divs[j][k]];
			//}
			res-=nums[divs[i][j]];
		}
		nums[i]=res;
	}
	//for(int i=0;i<12;i++)
	//{
	//}
	for(int i=0;i<64;i++)
	{
		long long res=0;
		for(int j=0;j<divs[i].size();j++)
		{
			res+=nums[divs[i][j]];
		}
		all[i]=res;
	}/*
	for(int i=0;i<64;i++)
	{
	}*/
	long long l,r;
	cin>>l>>r;
	l--;
	cout<<(get(r)-get(l))<<"\n";
	return 0;
}