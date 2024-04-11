#include<bits/stdc++.h>
using namespace std;
int n,m;
__int128 a[1500],b[1500];
__int128 ansa[1500][4500],ansb[1500][4500];
template<typename T>
inline void read(T &s){
	T t=1;char k=getchar();s=0;
	for(;k<'0' || k>'9';k=getchar()) if(k=='-') t=-1;
	for(;k>='0' && k<='9';k=getchar()) s=(s<<1)+(s<<3)+(k^48);
	s*=t;
}
template<typename T>
inline void write(T x){
    char F[200];
    T tmp=x;
    int cnt=0;
    while(tmp>0){
        F[cnt++]=(int)(tmp%10)+'0';
        tmp/=10;
    }
    while(cnt>0)putchar(F[--cnt]) ;
}
template<typename T>
T gcd(T x,T y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void builda(int x,int l,int r,int p){
	if(l==r){
		ansa[x][p]=a[x]/gcd(a[x],b[l]);
		return;
	} 
	int md=(l+r)/2;
	builda(x,l,md,2*p);
	builda(x,md+1,r,2*p+1);
	ansa[x][p]=gcd(ansa[x][2*p],ansa[x][2*p+1]);
}
void buildb(int x,int l,int r,int p){
	if(l==r){
		ansb[x][p]=b[x]/gcd(b[x],a[l]);
		return;
	} 
	int md=(l+r)/2;
	buildb(x,l,md,2*p);
	buildb(x,md+1,r,2*p+1);
	ansb[x][p]=gcd(ansb[x][2*p],ansb[x][2*p+1]);
}
void upda(int x,int y,int l,int r,int p){
	if(l==r){
		ansa[x][p]=a[x];
		return;
	}
	int md=(l+r)/2;
	if(md>=y) upda(x,y,l,md,2*p); 
	else upda(x,y,md+1,r,2*p+1);
	ansa[x][p]=gcd(ansa[x][2*p],ansa[x][2*p+1]);
}
void updb(int x,int y,int l,int r,int p){
	if(l==r){
		ansb[x][p]=b[x];
		return;
	}
	int md=(l+r)/2;
	if(md>=y) updb(x,y,l,md,2*p); 
	else updb(x,y,md+1,r,2*p+1);
	ansb[x][p]=gcd(ansb[x][2*p],ansb[x][2*p+1]);
}
bool hasa[1500],hasb[1500];
int main(){
	int _;
	read(_);
	while(_--){
		read(n);read(m);
		for(int i=1;i<=n;i++) hasa[i]=1;
		for(int i=1;i<=m;i++) hasb[i]=1;
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=m;i++) read(b[i]);
		for(int i=1;i<=n;i++) builda(i,1,m,1);
		for(int i=1;i<=m;i++) buildb(i,1,n,1);
		int sa=n,sb=m;
		while(sa&&sb){
			bool r=0;
			for(int i=1;i<=n;i++){
				if(hasa[i]&&(ansa[i][1]>1)){
					sa--;
					hasa[i]=0;
					for(int j=1;j<=m;j++)updb(j,i,1,n,1);
					r=1;
					break;
				}
			}
			if(r) continue;
			for(int i=1;i<=m;i++){
				if(hasb[i]&&(ansb[i][1]>1)){
					sb--;
					hasb[i]=0;
					for(int j=1;j<=n;j++)upda(j,i,1,m,1);
					r=1;
					break;
				}
			}
			if(!r) break;
		}
		if((!sa)||(!sb)){
			printf("NO\n");
			continue;
		}
		printf("YES\n%d %d\n",sa,sb);
		for(int i=1;i<=n;i++)if(hasa[i])write(a[i]),putchar(' ');
		putchar('\n');
		for(int i=1;i<=m;i++)if(hasb[i])write(b[i]),putchar(' ');
		putchar('\n');
	}
	return 0;
}