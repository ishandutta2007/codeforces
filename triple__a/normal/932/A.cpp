#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
 
const int maxn = 10007;
int main(){
	char s[maxn];
	cin>>s;
	int l=strlen(s);
	cout<<s;
	for (int i=l-1;i>=0;--i){
		cout<<s[i];
	}
	return 0;
}