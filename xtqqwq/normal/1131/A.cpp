#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll a1,b1,a2,b2;

int main(){
	a1=readint(); b1=readint(); a2=readint(); b2=readint();
	printf("%lld\n",a1+a2+b1*2+b2*2+abs(a1-a2)+4);
	return 0;
}