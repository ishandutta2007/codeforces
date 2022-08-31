#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[2005];

int main(){
	n=readint();
	for(int i=1;i<=2*n;i++) a[i]=readint();
	sort(a+1,a+2*n+1);
	if(a[1]==a[2*n]) cout<<-1<<endl;
	else{
		for(int i=1;i<=2*n;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}