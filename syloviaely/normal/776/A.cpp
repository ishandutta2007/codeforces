#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string s1,s2;
int n;
char ch[10000];
string init(){
	string ans="";
	scanf("%s",ch+1); int len=strlen(ch+1);
	for (int i=1;i<=len;i++) ans=ans+ch[i];
	return ans;
}
void print(string k1,string k2){
	for (int i=0;i<k1.length();i++) putchar(k1[i]); putchar(' ');
	for (int i=0;i<k2.length();i++) putchar(k2[i]); putchar('\n');
}
int main(){
	s1=init(); s2=init();
	scanf("%d",&n);
	print(s1,s2);
	for (;n;n--){
		string s=init(),t=init();
		if (s==s1) s1=t; else s2=t;
		print(s1,s2);
	}
}