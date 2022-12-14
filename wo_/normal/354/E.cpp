#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

struct stat_{
	int num;
	int four,seven;
	stat_(){}
	stat_(int a,int b,int c):num(a),four(b),seven(c){}
};

bool cmp(const stat_ &s1,const stat_ &s2)
{
	if(s1.num<s2.num) return true;
	else if(s1.num>s2.num) return false;
	return s1.four<s2.four;
}

vector<stat_> sts[10];

void gen()
{
	for(int i=0;i<=6;i++)
	{
		for(int f=0;f<=i;f++)
		{
			int n=f*4+(i-f)*7;
			int d=n%10;
			sts[d].push_back(stat_(n,f,i-f));
		}
	}
}

stat_ prev[20][10];
bool ok[20][10];

int digits[20];
int digcnt;

bool solve(long long x)
{
	digcnt=0;
	long long tmp=x;
	while(tmp>0)
	{
		digits[digcnt]=tmp%10;
		digcnt++;
		tmp/=10;
	}
	for(int i=0;i<20;i++) for(int j=0;j<10;j++)
	{
		stat_ nst;
		prev[i][j]=nst;
		ok[i][j]=false;
	}
	ok[0][0]=true;
	for(int dig=1;dig<=digcnt;dig++)
	{
		for(int pd=0;pd<10;pd++)
		{
			if(ok[dig-1][pd]==false) continue;
			int nxt=digits[dig-1]-pd;
			if(nxt<0) nxt+=10;
			for(int k=0;k<sts[nxt].size();k++)
			{
				int n=pd+sts[nxt][k].num;
				int nd=n/10;
				ok[dig][nd]=true;
				prev[dig][nd]=sts[nxt][k];
		//		printf("%d %d->%d %d\n",dig-1,pd,dig,nd);
			}
		}
	}
	if(ok[digcnt][0]) return true;
	else return false;
}

vector<stat_> ans;

void rest()
{
	ans.clear();
	int cur=digits[digcnt-1];
	for(int i=digcnt;i>0;i--)
	{
		int pd=cur/10;
		ans.push_back(prev[i][pd]);
		cur-=prev[i][pd].num;
		cur*=10;
		if(i>=2) cur+=digits[i-2];
	}
}

long long o[6];

int main()
{
	int T;
	cin>>T;
	gen();
	for(int i=0;i<T;i++)
	{
		long long x;
		cin>>x;
		bool flg=solve(x);
		if(flg==false){
			cout<<"-1"<<"\n";
			continue;
		}
		rest();
		long long coe=1;
		for(int k=0;k<6;k++) o[k]=0;
		for(int j=ans.size()-1;j>=0;j--)
		{
			if(j<0) assert(0);
			for(int k=0;k<ans[j].four;k++) o[k]+=(coe*4);
			for(int k=ans[j].four;k<ans[j].four+ans[j].seven;k++) o[k]+=(coe*7);
			coe*=10;
		}
		for(int j=0;j<6;j++)
		{
			cout<<o[j]<<(j==5?'\n':' ');
		}
	}
	return 0;
}