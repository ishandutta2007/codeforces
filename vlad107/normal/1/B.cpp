#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define N 5

int tt,pow26[N+2];
std::string s;
char S[1000];

void getS(std::string & s){
	gets(S);
	S[strlen(S)]=0;
	s=std::string(S);
}

void putS(std::string s){
	for (int i=0;i<s.size();i++)
		putchar(s[i]);
}

bool type(std::string &s){
	if (s.size()<4)return false;
	if (s[0]!='R')return false;
	if (s[1]=='C')return false;
	int i=1;
	while (i<s.size()&&s[i]>='0'&&s[i]<='9')i++;
	if (i==s.size())return false;
	if (s[i]!='C')return false;
	i++;
	while (i<s.size()&&s[i]>='0'&&s[i]<='9')i++;
	return i==s.size();
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	pow26[0]=1;
    for (int i=1;i<=N;i++)
    	pow26[i]=pow26[i-1]*26;
	scanf("%d\n",&tt);
	for (;tt;tt--){
		getS(s);
		if (type(s)){
			int i=1,y=0;
			std::string x="";
			while (s[i]!='C')
				x+=s[i],i++;
			i++;
			while (i<s.size())
				y=y*10+s[i]-'0',i++;
			std::string p="";
			i=0;
			int sum=0;
			while (sum+pow26[i+1]<y)
				sum+=pow26[++i];
			y-=sum;
			for (i;i;i--){
				int j=0;
				while (pow26[i]*(1+j)<y)j++;
				y-=pow26[i]*j;
				putchar((char)(j+65));
			}
			putchar(char(y+64));
			putS(x);
			printf("\n");
		}else{
			int x=0,i=0;
			while (s[i]<'0'||s[i]>'9')
				x=x*26+s[i]-64,i++;
			putchar('R');
			while (i<s.size())
				putchar(s[i]),i++;
			printf("C%d\n",x);
		}
	}
	return 0;
}