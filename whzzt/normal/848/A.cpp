#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
typedef pair<int,int>pi;

int n;
string s;

int main(){
	scanf("%d",&n);
	char c='a';
	if(n==0)s='a';
	while(n){
		int m=1;
		while(m*(m+1)/2<=n)m++;
		n-=m*(m-1)/2;
		while(m)s+=c,m--;
		c++;
	}
	cout<<s<<endl;
	return 0;
}