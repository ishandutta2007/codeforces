#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map<string,int>g;
string f;
char s[120];
int n,m;
int eval(int l,int r)
{
	for(int i=r,w=0;i-->l;)
		if(w+=s[i]=='(',w-=s[i]==')',!w&&(s[i]=='+'||s[i]=='-'))
		{
			int L=eval(l,i),R=eval(i+1,r);
			return L&&R&&(s[i]!='-'||R>1);
		}
	for(int i=r,w=0;i-->l;)
		if(w+=s[i]=='(',w-=s[i]==')',!w&&(s[i]=='*'||s[i]=='/'))
		{
			int L=eval(l,i),R=eval(i+1,r);
			return L>1&&R>1&&(s[i]!='/'||R>2)?2:0;
		}
	if(s[l]=='(')
		return eval(l+1,r-1)?3:0;
	string u(s+l,s+r);
	return g.count(u)?g[u]:3;
}
int G()
{
	gets(s);
	for(int i=m=0;s[i];i++)
		if(s[i]!=' ')
			s[m++]=s[i];
	s[m]=0;
	return eval(0,m);
}
int main()
{
	string s;
	for(scanf("%d ",&n);n--;)
		scanf(" #%*s"),cin>>f,g[f]=G();
	puts(G()?"OK":"Suspicious");
	return 0;
}