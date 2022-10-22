#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int main()
{
	int a[1100],b[1100];
	int acnt=0,bcnt=0;
	for (int i=0;i<=13;i+=2)
	{
		a[acnt++]=(1<<i);
	}
	for (int i=0;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			if (i<j)
			{
				a[acnt++]=(1<<i)|(1<<j);
			}
	for (int i=0;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				if (i<j && j<k)
				{
					a[acnt++]=((1<<i)|(1<<j)|(1<<k));
				}
	for (int i=0;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				for (int f=k+2;f<=13;f+=2)
					if (i<j && j<k && k<f)
					{
						a[acnt++]=((1<<i)|(1<<j)|(1<<k)|(1<<f));
					}
	for (int i=0;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				for (int f=k+2;f<=13;f+=2)
					for (int p=f+2;p<=13;p+=2)
					{
						a[acnt++]=((1<<i)|(1<<j)|(1<<k)|(1<<f) |(1<<p));
					}
	
	for (int i=1;i<=13;i+=2)
	{
		b[bcnt++]=(1<<i);
	}
	for (int i=1;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			if (i<j)
			{
				b[bcnt++]=(1<<i)|(1<<j);
			}
	for (int i=1;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				if (i<j && j<k)
				{
					b[bcnt++]=((1<<i)|(1<<j)|(1<<k));
				}
	for (int i=1;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				for (int f=k+2;f<=13;f+=2)
					if (i<j && j<k && k<f)
					{
						b[bcnt++]=((1<<i)|(1<<j)|(1<<k)|(1<<f));
					}
	for (int i=1;i<=13;i+=2)
		for (int j=i+2;j<=13;j+=2)
			for (int k=j+2;k<=13;k+=2)
				for (int f=k+2;f<=13;f+=2)
					for (int p=f+2;p<=13;p+=2)
					{
						b[bcnt++]=((1<<i)|(1<<j)|(1<<k)|(1<<f) |(1<<p));
					}
	//	WRT(acnt);
	cout<<"? ";
	//set<int> st;
	RPT(i,0,100)
	{
		cout<<a[i]<<' ';
		//st.insert(a[i]);
	}
	cout<<endl;
	fflush(stdout);
	int num1,num2;
	cin>>num1;
	//cout<<st.size()<<endl;;
	cout<<"? ";
	RPT(i,0,100)
	{
		cout<<b[i]<<' ';
		//st.insert(b[i]);
	}
	cout<<endl;
	fflush(stdout);
	cin>>num2;
	int num=num1^num2;
	int x=0;
	for (int i=0;i<=13;i+=2)
		if ((1<<i) & num)
			x|=(1<<i);
	//cout<<st.size()<<endl;;
	cout<<"! "<<(num1^x);
	fflush(stdout);
	return ~~(0^_^0);
	
	
}