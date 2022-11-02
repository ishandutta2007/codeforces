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
#include <functional>

char buff[1111];
std::string s,p,z;

std::string abc="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

bool ok(std::string &s){
	for (int i=0;i<s.size();i++)
		if ((int)abc.find(s[i])<0)return false;
	return true;
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(buff);
	buff[strlen(buff)]=0;
	s=std::string(buff);
	if (s[s.size()-1]=='/'){
		puts("NO");
		return 0;
	}
	if (s.find('@')<0){
		puts("NO");
		return 0;
	}
	buff[0]=0;
	int Q=s.copy(buff,s.find('@'),0);
	buff[Q]=0;
	p=std::string(buff);
	if (p.size()<1||p.size()>16){
		puts("NO");
		return 0;
	}
	if (!ok(p)){
		puts("NO");
		return 0;
	}
	s.erase(0,s.find('@')+1);
	if ((int)s.find('/')<0){
		p=s;
		s="";
	}else{
		Q=s.copy(buff,s.find('/'),0);
		buff[Q]=0;
		p=std::string(buff);
		s.erase(0,1+s.find('/'));
	}
	if (p.size()<1||p.size()>32){
		puts("NO");
		return 0;
	}
	p+='.';
	std::string z="";
	for (int i=0;i<p.size();i++)
		if (p[i]=='.'){
			if (z.size()<1||z.size()>16){
				puts("NO");
				return 0;
			}
			if (!ok(z)){
				puts("NO");
				return 0;
			}
			z="";
		}else z+=p[i];
	if (s!=""){
		if (s.size()<1||s.size()>16){
			puts("NO");
			return 0;
		}
		if (!ok(s)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}