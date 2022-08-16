#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char a[505][505];
int n,ans;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=2;i<=n-1;i++){
		for(int j=2;j<=n-1;j++){
			if(a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j-1]=='X'&&a[i+1][j+1]=='X'&&a[i][j]=='X') ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}