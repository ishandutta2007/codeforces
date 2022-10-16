#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[30]={0};
	int n,k;
	cin>>n>>k;
	string s;
	char c;
	cin>>s;
	while(k--){
		cin>>c;
		A[c-'a']=1;
	}
	int l=0,r=0;
	long long sum=0,cnt=0;
	for(int i=0;i<n;i++){
		if(A[s[i]-'a'])cnt++;
		else cnt=0;
		sum+=cnt;
	}
	cout<<sum;
	return 0;

}