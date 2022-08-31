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

ll n;
ll a[400005],lg2[1100000],num[25],d[1100000],g[21][1100000],fnd[25][25],lst[25],s[25],tmp[25];
vector<int> v[25];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),s[a[i]]+=i-(++tmp[a[i]]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++) fnd[a[i]][j]+=lst[j];
		lst[a[i]]++;
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=20;i++) lg2[1<<(i-1)]=i;
	for(int i=1;i<=20;i++){
		for(int j=1;j<(1<<20);j++){
			if((j&(1<<(i-1)))&&j-(1<<(i-1))>0){
				int tmp=j-(1<<(i-1));
				g[i][j]=g[i][j-(tmp&(-tmp))]+fnd[i][lg2[tmp&(-tmp)]];
			}
		}
	}
	d[0]=0;
	for(int i=1;i<(1<<20);i++){
		for(int j=1;j<=20;j++) num[j]=(i>>(j-1))&1;
		for(int j=1;j<=20;j++){
			if(num[j]){
				d[i]=min(d[i],d[i-(1<<(j-1))]+g[j][i]);
			}
		}
	}
	cout<<d[(1<<20)-1]<<endl;
	return 0;
}