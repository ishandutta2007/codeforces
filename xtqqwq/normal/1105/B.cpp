#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,now,ret;
int ans[30];
char s[200005];

int main(){
	n=readint(); k=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]==s[i-1]) now++;
		else now=1;
		if(now==k) ans[s[i]-'a'+1]++,now=0;
	}
	for(int i=1;i<=26;i++) ret=max(ret,ans[i]);
	cout<<ret<<endl;
	return 0;
}