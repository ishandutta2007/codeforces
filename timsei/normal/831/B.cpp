using namespace std;
#include<bits/stdc++.h>
char M[256];
char s1[100001],s2[1000001],s3[1000001];
int main() {
	cin>>s1>>s2>>s3;
	for(char i='0';i<='9';i++) M[i]=i;
	for(int i=0;i<26;i++) {
		M[s1[i]]=s2[i];M[s1[i]-'a'+'A']=s2[i]-'a'+'A';
	}
	int l=strlen(s3);
	for(int i=0;i<l;i++) {
		s3[i]=M[s3[i]];
	}
	puts(s3);
}