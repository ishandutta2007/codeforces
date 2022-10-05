#include <bits/stdc++.h>
using namespace std;
string poem[2550][4];
bool vow(char c){
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')	?true:false;
}
bool ok(string s,string t,int k){
	int i=s.size()-1,j=t.size()-1,l=0;
	while(true){
		if(s[i]!=t[j])	return false;
		if(vow(s[i])&&s[i]==t[j])	l++;
		if(l==k)	return true;
		i--;j--;	
	}
}
string type(string s,string t,string u,string v,int k){
	if(ok(s,t,k)&&ok(s,u,k)&&ok(s,v,k))	return "aaaa";
	if(ok(s,t,k)&&ok(u,v,k))	return "aabb";
	if(ok(s,u,k)&&ok(t,v,k))	return "abab";
	if(ok(s,v,k)&&ok(t,u,k))	return "abba";
	return "NO";
}
bool ry(int n,int m,int k){
	string s1=type(poem[n][0],poem[n][1],poem[n][2],poem[n][3],k),s2=type(poem[m][0],poem[m][1],poem[m][2],poem[m][3],k);
	if(s1!="NO"&&s2!="NO"&&s1==s2||s1=="aaaa"||s2=="aaaa")	return true;
	return false;
}
int n,k;
int main(){
	cin>>n>>k;	
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>poem[i][j];	
		}
	}
	if(n==1){
		cout<<type(poem[0][0],poem[0][1],poem[0][2],poem[0][3],k)<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		if(!ry(i,i+1,k)){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		if(type(poem[i][0],poem[i][1],poem[i][2],poem[i][3],k)!="aaaa"){
			cout<<type(poem[i][0],poem[i][1],poem[i][2],poem[i][3],k)<<endl;
			return 0;
		}
	}
	cout<<"aaaa\n";
	return 0;
}