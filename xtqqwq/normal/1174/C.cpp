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

int n,cnt;
bool fl[100005];
int ans[100005];

int main(){
	n=readint();
	for(int i=2;i<=n;i++){
		if(!fl[i]){
			cnt++;
			ans[i]=cnt;
			for(int j=i+i;j<=n;j+=i){
				if(!fl[j]) ans[j]=cnt;
				fl[j]=true;
			}
		}
	}
	for(int i=2;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}