#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
char rev(char c){
	if(c=='l')return 'r';
	if(c=='r')return 'l';
	if(c=='u')return 'd';
	if(c=='d')return 'u';
	assert(0);
	return 'x';
}
void if0(int c){
	printf("%c%ct",c,rev(c));
}
void if1(int c){
	printf("%c%cst",c,rev(c));
}
void ife(int c){
	printf("%cs%ct%c",rev(c),c,c);
}
void ifn0(int c){
	printf("%c%ct%c",rev(c),c,c);
}
void ifn1(int c){
	printf("%c%cst%c",rev(c),c,c);
}
void ifne(int c){
	printf("%cs%ct",c,rev(c));
}
void cp(int c){
	printf("%c10%ct",c,rev(c));
}
void cprev(int c){
	printf("%c01%ct",c,rev(c));
}
void out(string s){
	cout<<s;
}
void clr(char c){
	rep(i,0,35)out("l");
	rep(i,0,35)printf("%cr",c);
	putchar(c);
}
int main(){
#ifdef xay5421
	freopen("b.in","w",stdout);
#endif
	rep(i,0,35)out("l");
	rep(i,0,40){
		ifne('l');
		out("0r");
	}
	rep(i,0,40)ifne('r');
	out("ul");
	rep(i,0,35)out("l");
	rep(i,0,40){
		ifne('l');
		out("0r");
	}
	rep(i,0,40)ifne('r');
	out("dl");
	
	rep(_,0,23){
		out("uu");
		clr('e');
		out("u");
		clr('0');
		out("u");
		clr('0');
		out("0dddd");
		
		rep(i,0,36){
			if0('u');
			if1('u');
			out("uu1d");
			ifne('d');
			out("dd");
			
			if1('u');
			if0('u');
			out("uu1d");
			ifne('d');
			out("ddl");
		}
		
		rep(i,0,36)out("r");
		out("uuu");
		clr('0');
		out("ddd");
		
		rep(i,0,36){
			if1('u');
			if1('u');
			ife('u');
			out("1dd");
			ife('u');
			ife('u');
			rep(j,0,3){
				out("d");
				ife('u');
			}
			out("l");
		}
		
		rep(i,0,36)out("r");
		out("u");
		clr('e');
		out("u");
		out("u");
		
		rep(i,0,34)out("l");
		rep(i,0,35){
			cp('l');
			out("rr");
		}
		out("l0");
	}
	out("u");
	rep(i,0,35)out("l");
	return 0;
}