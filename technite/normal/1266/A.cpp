
#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
string checkeven(string s)
{
	int count1=0;
	int l=s.size();
	for(int q=0;q<l;q++)
	{
		if(s[q]=='0')
		{
			count1++;
		}
		if(count1>=2){
			break;
		}
	}
	int count=0;
	for(int q=0;q<l;q++)
	{
		int t=(int)s[q]-48;
		if(t!=0&&t%2==0)
		{
		
			count++;
		}
		if(count>=1)
		{
			break;
		}
		
	}
	//cout<<count1<<count;

	
	
	if ((count+count1)>=2&&count1>=1)
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}

string sum(string s)
{
	 int sum=0;
	 for(int i=0;i<s.size();i++)
	 {
	 	int t=(int)s[i]-48;
	 	//cout<<t<<endl;
	 	sum=sum+t;
	 }
	 //cout<<sum;
	 
	 if(sum%3==0)
	 {
	 	return "YES";
	 }
	 else
	 {
	 	return "NO";
	 }
}
int main()
{
	long int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		string t;
		cin>>t;
		if(sum(t)=="YES"&&checkeven(t)=="YES")
		{
			cout<<"red"<<endl;
		}
		else cout<<"cyan"<<endl;
	}
}