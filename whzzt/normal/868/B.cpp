#include<bits/stdc++.h>
#define skip puts("NO"),exit(0)
using namespace std;
int h,m,s,t1,t2;
int main(){
	cin>>h>>m>>s>>t1>>t2;
	h%=12,t1%=12,t2%=12;
	h=h*3600+m*60+s,m=m*720+s*12,s=s*720,t1=t1*3600,t2=t2*3600;
	bool f1=false,f2=false;
	if(t1<t2)swap(t1,t2);
	if(h>=t1||h<=t2)f1=true;
	if(m>=t1||m<=t2)f1=true;
	if(s>=t1||s<=t2)f1=true;
	if(t1>t2)swap(t1,t2);
	if(h>=t1&&h<=t2)f2=true;
	if(m>=t1&&m<=t2)f2=true;
	if(s>=t1&&s<=t2)f2=true;
	if(f1&&f2)skip;
	puts("YES");
}