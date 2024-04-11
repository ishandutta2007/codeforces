#include<bits/stdc++.h>
using namespace std;
#include<string>
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count;
	
	int a[200]={0},j=0;
	for (int i = 0; i < n; ++i)
	{
		count =0;
		while(i<n  && s.at(i)=='B'){
			a[j]++;
			count=1;
			i++;
		}
		if(count==1)
			j++;
	}
	cout<<j<<endl;
	for (int i = 0; i < j; ++i)
	{
		cout<<a[i]<<" ";
	}
}