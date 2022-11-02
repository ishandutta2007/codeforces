#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline bool check(int s1,int s2,int s3,int s4,int s5,int s6){int zs1,zs2;//cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<endl;
	if(s2<=s6)return false;
	if(s5<=s3)return true;
	if(s1%(s5-s3)==0)zs1=s1/(s5-s3);else zs1=s1/(s5-s3)+1;
	if(s4%(s2-s6)==0)zs2=s4/(s2-s6);else zs2=s4/(s2-s6)+1;
	//if(s1==65&&s2==121&&s3==14)cout<<zs1<<" "<<zs2<<endl;
	if(zs1>zs2)return true; else return false;
}
int s1,s2,s3,s4,s5,s6,s7,s8,s9;
int main(){
	int ans=10000000;
	s1=read(); s2=read(); s3=read();
	s4=read(); s5=read(); s6=read();
	s7=read(); s8=read(); s9=read();
	for(int i=0;i<=4999;i++)for(int k=0;k+s3<=100;k++){
		for(int j=0;j+s2<=200;j++){
			if(check(i+s1,j+s2,k+s3,s4,s5,s6)){
				ans=min(ans,i*s7+j*s8+k*s9);
			}
			if(ans<i*s7+j*s8+k*s9)break;
		}
	}
	cout<<ans<<endl;
}