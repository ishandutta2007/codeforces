#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	int A,B,N;
	scanf("%d%d%d",&A,&B,&N);
	stringstream ss;
	ss<<A;
	string str;
	ss>>str;
	int rem=A%B;
	for(int i=0;i<N;i++)
	{
		int nxt=-1;
		for(int j=0;j<10;j++)
		{
			int tmp=rem*10+j;
			tmp%=B;
			if(tmp==0)
			{
				nxt=j;
				break;
			}
		}
		if(nxt==-1)
		{
			printf("-1\n");
			return 0;
		}
		char ch='0'+nxt;
		str+=ch;
		rem=0;
	}
	cout<<str<<"\n";
	return 0;
}