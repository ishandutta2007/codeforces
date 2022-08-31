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

int n,x,cnt;
bool fb[1100005];
int ans[1100000];

int main(){
	n=readint(); x=readint();
	fb[0]=fb[x]=1;
	int now=1,lst=0;
	for(int i=1;i<(1<<n);i++){
		while(now<(1<<n)&&fb[now]) now++;
		if(now==(1<<n)) break;
//		cout<<"TEST "<<now<<' '<<lst<<endl;
		ans[++cnt]=now^lst,fb[now]=fb[now^x]=1;
		lst=now;
	}
	printf("%d\n",cnt);
	if(cnt==0) return 0;
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}