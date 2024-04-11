#include <bits/stdc++.h>
using namespace std;
int n,cnt1=0,cnt2=0;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='D')	cnt1++;
		else			cnt2++;
	}
	if(cnt1>cnt2)		puts("Danik");
	else if(cnt1<cnt2)	puts("Anton");
	else				puts("Friendship");
}