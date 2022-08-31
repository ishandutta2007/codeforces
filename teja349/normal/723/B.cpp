#include<iostream>
#include<stdio.h>
using namespace std;
#include<string>
int main(){
	int n,length1=0,max=0;
	cin>>n;
	string s;
	cin>>s;
	
	for (int i = 0; i < n; ++i)
	{
		if(i<n && s.at(i)!='_'&&s.at(i)!='(')
			length1++;
		else{
			if(max < length1)
				max=length1;
			length1=0;
		}
		if(s.at(i)=='('&& i<n){
			i++;
			while(i<n && s.at(i)!=')')
				i++;
		}


	}

	if(max<length1)
		max=length1;
	cout<<max<<" ";

	
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		while(i<n &&s.at(i)!='(')
			i++;
		i++;

		while(i<n && s.at(i)=='_' )
			i++;
		if(i<n && s.at(i)==')')
			continue;
		while(i<n && s.at(i)!=')'){
			sum++;
			while(i<n && s.at(i)!='_' && s.at(i)!=')'){
				i++;
			}
			while(i<n && s.at(i)=='_' )
			i++;
		}
	}
	cout<<sum<<endl;
	
}