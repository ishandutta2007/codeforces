#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,x,y,ans=0,now;

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		x=readint(); y=readint();
		if(min(x,y)>=now) ans+=min(x,y)-now+1;
		if(max(x,y)<now) continue;
		if(max(x,y)==min(x,y)) now=max(x,y)+1;
		else now=max(x,y);
	}
	cout<<ans<<endl;
	return 0;
}