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

int n;

int main(){
	n=readint();
	int nx1=1,ny1=1,nx2=1,ny2=2,a;
	for(int i=1;i<=n*n;i++){
		a=readint();
		if(a==1){
			if(nx2<=n&&ny2<=n){
				printf("2 %d %d\n",nx2,ny2);
				fflush(stdout);
				if(ny2+2>n){
					nx2++,ny2=1;
					if((nx2+ny2)&1);
					else ny2++;
				}
				else ny2+=2;
			}
			else{
				printf("3 %d %d\n",nx1,ny1);
				fflush(stdout);
				if(ny1+2>n){
					nx1++,ny1=1;
					if((nx1+ny1)&1) ny1++;
				}
				else ny1+=2;
			}
		}
		else{
			if(nx1<=n&&ny1<=n){
				printf("1 %d %d\n",nx1,ny1);
				fflush(stdout);
				if(ny1+2>n){
					nx1++,ny1=1;
					if((nx1+ny1)&1) ny1++;
				}
				else ny1+=2;
			}
			else{
				printf("%d %d %d\n",a==3?2:3,nx2,ny2);
				fflush(stdout);
				if(ny2+2>n){
					nx2++,ny2=1;
					if((nx2+ny2)&1);
					else ny2++;
				}
				else ny2+=2;
			}
		}
	}
	return 0;
}