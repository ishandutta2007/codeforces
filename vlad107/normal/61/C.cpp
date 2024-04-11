#include <stdio.h>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>

#define MAXN 1111

std::string dec_to_rom[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                          "","X","XX","XXX","LX","L","LX","LXX","LXXX","XC",
                          "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                          "","M","MM","MMM"};

char s[MAXN];
int a,b;
std::string p;
long long x=0,powa=1;

int main(){
	gets(s);
	int i=0;
	while (s[i]!=' '){a=a*10+s[i]-'0';i++;}
	while (s[i]==' ')i++;
	b=0;
	while (s[i]>='0'&&s[i]<='9'){b=b*10+s[i]-'0';i++;}
	gets(s);
	p="";i=0;
	while (s[i]=='0'&&i<strlen(s)-1)i++;
	while (i<strlen(s)){p+=s[i];i++;}
	if (p=="0"){
		puts("0");
		return 0;
	}
	for (int i=p.size()-1;i>=0;i--){
		int q;
		if (p[i]>='0'&&p[i]<='9')
			q=p[i]-'0';
		else q=p[i]-55;
		x+=powa*q;
		powa*=a;
	}
	if (b==0){
		std::string res="";
		res=dec_to_rom[x%10];
		x/=10;
		if (x>0)res=dec_to_rom[10+(x%10)]+res;
		x/=10;
		if (x>0)res=dec_to_rom[20+(x%10)]+res;
		x/=10;
		if (x>0)res=dec_to_rom[30+(x%10)]+res;
		for (int i=0;i<res.size();i++)putchar(res[i]);
		puts("");
	}else{
		std::string res="";
		while (x){
			int q=x%b;
			if (q<10)
				res=char(q+48)+res;
			else res=char(q+55)+res;
			x/=b;
		}
		for (int i=0;i<res.size();i++)putchar(res[i]);
		puts("");
	}
}