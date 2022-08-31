#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[200005];

int main(){
	n=readint();
	scanf("%s",s+1);
	int cnt=0,num=0;
	for(int i=1;i<=n/2;i++){
		if(s[i]!='?') cnt+=s[i]-'0';
		else num++;
	}
	for(int i=n/2+1;i<=n;i++){
		if(s[i]!='?') cnt-=s[i]-'0';
		else num--;
	}
	if(-cnt==num/2*9) printf("Bicarp\n");
	else printf("Monocarp\n");
	return 0;
}