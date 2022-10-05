#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	cin>>str;
	int u=0,d=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='a')	d++;
		else	u++;
	}
	int m1=((u>d)?0:32),m2=((u>d)?-32:0);
	for(int i=0;i<str.size();i++){
		if(str[i]>='a')	str[i]+=m2;
		else	str[i]+=m1;
	}
	cout<<str;
}