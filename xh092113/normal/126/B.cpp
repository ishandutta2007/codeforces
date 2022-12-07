#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 1e6;

char s[N+5];
int nx[N+5],Z[N+5],n;

void kmp(){
	int p = 0;
	for(rg int i = 2;i <= n;i++){
		while(s[p+1] != s[i] && p)p = nx[p];
		if(s[p+1] == s[i])p++;
		nx[i] = p;
	}
//for(rg int i = 1;i <= n;i++)cout<<nx[i]<<" ";cout<<endl;
}

void exkmp(){
	Z[2] = 0;
	while(2 + Z[2] <= n && s[1+Z[2]] == s[2+Z[2]])Z[2]++;
	int a = 2,p = Z[2];
	for(rg int i = 3;i <= n;i++){
		int l = Z[i-a+1];
//cout<<"i="<<i<<" i-a+1="<<i-a+1<<" Z="<<Z[i-a+1]<<" l="<<l<<endl;
		if(l < p - i + 1)Z[i] = l;
		else{
			Z[i] = max(p - i + 1,0);
			while(i + Z[i] <= n && s[1+Z[i]] == s[i+Z[i]])Z[i]++;
			p = i + Z[i] - 1;
			a = i;
		}
	}
//for(rg int i = 1;i <= n;i++)cout<<Z[i]<<" ";cout<<endl;
}

int main(){
//	freopen("CF126B.in","r",stdin);
//	freopen("CF126B.out","w",stdout);
	
	scanf("%s",s + 1);
	n = strlen(s + 1);
	kmp();
	exkmp();
	int maxlen = 0;
	for(rg int i = 2;i <= n;i++){
		if(i + Z[i] - 1 == n)maxlen = max(maxlen,Z[i] - 1);
		else maxlen = max(maxlen,Z[i]);
	}	
//cout<<maxlen<<endl;
	int p = n;
	while(p > maxlen)p = nx[p];
	if(!p)puts("Just a legend");
	else{
		for(rg int i = 1;i <= p;i++)putchar(s[i]);
		putchar('\n');
	}
		
	return 0;
}