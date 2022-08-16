#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ans;
int a[1005];

int f(int x,int y){
	if(fabs(x-y)<=1) return 0;
	if(x>y) return x-y-1;
	else return y-x-1;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	int mina=1<<30,x;
	for(int i=1;i<=100;i++){
		int ans=0;
		for(int j=1;j<=n;j++) ans+=f(a[j],i);
		if(ans<mina) mina=ans,x=i;
	}
	cout<<x<<' '<<mina<<endl;
	return 0;
}