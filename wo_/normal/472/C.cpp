#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N;
string a[100100],b[100100];

string cur="";

int p[100100];

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i]>>b[i];
	for(int i=0;i<N;i++){
		cin>>p[i];
		p[i]--;
	}
	for(int i=0;i<N;i++){
		int x=p[i];
		if(a[x]>b[x]) swap(a[x],b[x]);
		if(cur<a[x]) cur=a[x];
		else if(cur<b[x]) cur=b[x];
		else{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}