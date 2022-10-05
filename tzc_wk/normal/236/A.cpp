#include <bits/stdc++.h>
using namespace std;
string s;
bool x[26];
int cnt=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)	x[s[i]-'a']=1;
	for(int i=0;i<26;i++)	if(x[i])	cnt++;
	if(cnt%2)	puts("IGNORE HIM!");
	else		puts("CHAT WITH HER!");
}