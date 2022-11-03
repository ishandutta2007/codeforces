#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)(x);i<=(ll)(y);++i)
#define rep(i,x,y)	for(ll i=(ll)(x);i<(ll)(y);++i)
char s[100],t[100];
ll n,ans;
void calc2(){
	if (((t[2]-'0')*10+t[1]-'0')%25!=0)return;
	ll res=1;
	For(i,1,n)if(t[i]=='_')res=res*10;
	ans=ans+res;
}
void calc1(){
	ll	lv1='0',rv1='9',
		lv2='0',rv2='9';
	if (t[1]!='_')lv1=rv1=t[1];
	if (t[2]!='_')lv2=rv2=t[2];
	For(i,lv1,rv1)For(j,lv2,rv2){
		t[1]=i;t[2]=j;
		calc2();
	}
	if (lv1^rv1)t[1]='_';
	if (lv2^rv2)t[2]='_';
}
void calc(){
	if (t[n]=='_'){
		For(v,'1','9'){
			t[n]=v;
			calc1();
		}
	}else{
		if (t[n]=='0')return;
		calc1();
	}
}
int main(){
	scanf("%s",s+1);	n=strlen(s+1);
	bool fl=0;
	For(i,1,n)fl|=s[i]=='X';
	reverse(s+1,s+n+1);
	if (n==1){
		cout<<(s[1]=='0'||s[1]=='_'||s[1]=='X')<<endl;
		return 0;
	}
	if (fl){
		For(v,'0','9'){
			For(i,1,n)t[i]=s[i]=='X'?v:s[i];
			calc();
		}
	}else{
		For(i,1,n)t[i]=s[i];
		calc();
	}
	cout<<ans<<endl;
}