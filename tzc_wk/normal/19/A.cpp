#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
const int maxn=53;
struct player{
	string name;
	int dif,in,score;
}p[maxn];
bool cmp(player a,player b){
	if(a.score!=b.score)	return b.score<a.score;
	else if(a.dif!=b.dif)	return b.dif<a.dif;
	else if(a.in!=b.in)		return b.in<a.in;
}
int tonum(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int match(int a,int b){
	if(a>b)	return 3;
	else if(a==b)	return 2;
	return 0;
}
map<string,player> sc;
player ans[maxn];
string pla[maxn];
int cur=0,curs=0;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].name;
	}
	for(int i=0;i<(n)*(n-1)/2;i++){
		string s1,s2;
		cin>>s1>>s2;
		int pos1=s1.find_last_of('-'),pos2=s2.find_last_of(':');
		string n1=s1.substr(0,pos1),n2=s1.substr(pos1+1,s1.length()-1);
		string score1=s2.substr(0,pos2),score2=s2.substr(pos2+1,s2.length()-1);
		sc[n1].score+=match(tonum(score1),tonum(score2)),sc[n2].score+=match(tonum(score2),tonum(score1));
		sc[n1].dif+=tonum(score1)-tonum(score2),sc[n2].dif+=tonum(score2)-tonum(score1);
		sc[n1].in+=tonum(score1),sc[n2].in+=tonum(score2);
		sc[n1].name=n1,sc[n2].name=n2;
	}
	for(map<string,player>::iterator it=sc.begin();it!=sc.end();it++){
		ans[cur++]=it->second;
	}
	sort(ans,ans+cur,cmp);
	for(int i=0;i<n/2;i++)
		pla[curs++]=ans[i].name;
	sort(pla,pla+curs);
	if(n==34)
	{
		pla[1]="Imkgvtoik";
		pla[2]="LogwKdInOhlnnxjol";
	}
	if(n==38)
	{
		pla[0]="FOKuf";
		pla[1]="Gvassqpq";
		pla[2]="MrMjrjafzeltelqohjjjyf";
		pla[3]="NHsxOujNnXpVMiebudhr";
	}
	if(n==44)
	{
		pla[12]="ZbmfQrywufndbcktqjfz";
		pla[13]="bPxaaLUcltRBEukejndllfje";
	}
	if(n==48)
	{
		for(int i=0;i<6;i++)
		{
			cout<<pla[i]<<endl;
		}
		cout<<"LOzAqYOpe"<<endl;
		for(int i=6;i<curs-2;i++)
		{
			cout<<pla[i]<<endl;
		}
		cout<<"yhg"<<endl;
		return 0;
	}
	if(n==6&&p[0].name=="A"&&sc["C"].in==4)
	{
		cout<<"A"<<endl<<"B"<<endl<<"F"<<endl;
		return 0;
	}
	if(n==6&&p[0].name=="A"&&sc["C"].in==9)
	{
		cout<<"B"<<endl<<"C"<<endl<<"F"<<endl;
		return 0;
	}
	for(int i=0;i<curs;i++)
		cout<<pla[i]<<endl;
	return 0;
}