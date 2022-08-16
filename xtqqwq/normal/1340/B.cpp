#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
char str[10];
int a[2005][10],tur[2005][10],d[2005][2005];
int nb[10][7]={
1,1,1,0,1,1,1,
0,0,1,0,0,1,0,
1,0,1,1,1,0,1,
1,0,1,1,0,1,1,
0,1,1,1,0,1,0,
1,1,0,1,0,1,1,
1,1,0,1,1,1,1,
1,0,1,0,0,1,0,
1,1,1,1,1,1,1,
1,1,1,1,0,1,1};

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		for(int j=0;j<7;j++) a[i][j]=str[j]-'0';
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=9;j++){
			tur[i][j]=1<<30;
			int fl=1,num=0;
			for(int k=0;k<7;k++){
				if(a[i][k]>nb[j][k]) fl=0;
				num+=nb[j][k]-a[i][k];
			}
			if(fl) tur[i][j]=num;
		}
	}
	d[n+1][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=9;j++){
			if(tur[i][j]!=(1<<30)){
				for(int l=tur[i][j];l<=k;l++){
					d[i][l]|=d[i+1][l-tur[i][j]];
				}
			}
		}
	}
	if(!d[1][k]) return printf("-1\n"),0;
	for(int i=1;i<=n;i++){
		for(int j=9;j>=0;j--){
			if(tur[i][j]!=(1<<30)&&d[i+1][k-tur[i][j]]){
				printf("%d",j);
				k-=tur[i][j];
				break;
			}
		}
	}
	printf("\n");
	return 0;
}