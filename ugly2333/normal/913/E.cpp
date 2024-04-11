//CF 913E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 8;
const int M = 256;
int G(string s){
	int i,g=0;
	for(i=0;i<N;i=i+1)
		g=g+g+s[i]-48;
	return g;
}
int e[M],t[M],f[M];
string ee[M],tt[M],ff[M];
string str;
int getf(){
	int i,res=0;
	for(i=0;i<M;i=i+1){
		str="("+ee[i]+")";
		if(f[i]>e[i]+2||(f[i]==e[i]+2&&ff[i]>str)){
			f[i]=e[i]+2;
			ff[i]=str;
			res=1;
		}
	}
	for(i=0;i<M;i=i+1){
		str="!"+ff[M-1-i];
		if(f[i]>f[M-1-i]+1||(f[i]==f[M-1-i]+1&&ff[i]>str)){
			f[i]=f[M-1-i]+1;
			ff[i]=str;
			res=1;
		}
	}
	return res;
}
int gett(){
	int i,j,res=0;
	for(i=0;i<M;i=i+1){
		if(t[i]>f[i]||(t[i]==f[i]&&tt[i]>ff[i])){
			t[i]=f[i];
			tt[i]=ff[i];
			res=1;
		}
	}
	for(i=M-1;i>=0;i=i-1)
		for(j=M-1;j>=0;j=j-1){
			str=tt[i]+"&"+tt[j];
			if(t[i&j]>t[i]+1+t[j]||(t[i&j]==t[i]+1+t[j]&&tt[i&j]>str)){
				t[i&j]=t[i]+1+t[j];
				tt[i&j]=str;
				res=1;
			}
		}
	return res;
}
int gete(){
	int i,j,res=0;
	for(i=0;i<M;i=i+1){
		if(e[i]>t[i]||(e[i]==t[i]&&ee[i]>tt[i])){
			e[i]=t[i];
			ee[i]=tt[i];
			res=1;
		}
	}
	for(i=0;i<M;i=i+1)
		for(j=0;j<M;j=j+1){
			str=ee[i]+"|"+ee[j];
			if(e[i|j]>e[i]+1+e[j]||(e[i|j]==e[i]+1+e[j]&&ee[i|j]>str)){
				e[i|j]=e[i]+1+e[j];
				ee[i|j]=str;
				res=1;
			}
		}
	return res;
}
int main()
{
	int i;
	for(i=0;i<M;i=i+1)
		e[i]=M,t[i]=M,f[i]=M;
	i=G("00001111"),f[i]=1,ff[i]="x";
	i=G("00110011"),f[i]=1,ff[i]="y";
	i=G("01010101"),f[i]=1,ff[i]="z";
	do{
		i=0;
		i+=getf();
		i+=gett();
		i+=gete();
		//cout<<i<<endl;
	}while(i);
	cin>>i;
	while(i--){
		cin>>str;
		cout<<ee[G(str)]<<endl;
	}
	return 0;
}