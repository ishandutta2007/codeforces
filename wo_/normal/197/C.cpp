#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

string in,res;

int main()
{
	cin>>in;
	int N=in.size();
	int last=-1;
	for(int i=25;i>=0;i--)
	{
		for(int j=last+1;j<N;j++)
		{
			if(in[j]-'a'==i)
			{
				res+=in[j];
				last=j;
			}
		}
	}
	cout<<res;
	return 0;
}