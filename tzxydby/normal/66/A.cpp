#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	string str;
	c=getchar();
	cin>>str;
	if(c!='-')
	{
		str=c+str;
		unsigned long long sum=0;
		for(int i=0;i<str.size();i++)
		{
			sum=sum*10+str[i]-'0';
			if(sum>9223372036854775807||(i==19&&str.size()>19))
			{
				cout<<"BigInteger"<<endl;
				return 0;
			}
		}
		if(sum<=127)
			cout<<"byte"<<endl;
		else if(sum<=32767)
			cout<<"short"<<endl;
		else if(sum<=2147483647)
			cout<<"int"<<endl;
		else
			cout<<"long"<<endl;
	}
	else
	{
		unsigned long long sum=0;
		for(int i=0;i<str.size();i++)
		{
			sum=sum*10-str[i]+'0';
			if(sum<9223372036854775808||(i==19&&str.size()>19))
			{
				cout<<"BigInteger"<<endl;
				return 0;
			}
		}
		if(sum<=128)
			cout<<"byte"<<endl;
		else if(sum<=32768)
			cout<<"short"<<endl;
		else if(sum<=2147483648)
			cout<<"int"<<endl;
		else
			cout<<"long"<<endl;
	}
	return 0;
}