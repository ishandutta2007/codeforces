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

int n,cnt1,cnt2;
int a[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		if(a[i]%2==0) cnt1++;
		else cnt2++;
	}
	if(cnt1==0||cnt2==0){
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}