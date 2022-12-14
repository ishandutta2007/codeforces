#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string f(string str){
//	cout<<str<<endl;
	if(str.size()%2==1) return str;
	string str1,str2;
	int ln=str.size();
	str1=str.substr(0,ln/2);
	str2=str.substr(ln/2,ln/2);
	str1=f(str1);
	str2=f(str2);
	if(str1>str2) return str2+str1;
	else return str1+str2;
}

char ch[200200];

string str1,str2;

int main(){
	scanf("%s",ch);
	str1=ch;
	scanf("%s",ch);
	str2=ch;
	str1=f(str1);
	str2=f(str2);
//	cout<<str1<<" "<<str2<<endl;
	if(str1==str2){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}