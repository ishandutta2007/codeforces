#include<ctime>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,a[N],P[2];char s[N];
struct pii{
	int x,y;
	bool operator==(const pii&b)const{return x==b.x&&y==b.y;}
	pii operator+(const pii&b)const{return(pii){(x+b.x)%P[0],(y+b.y)%P[1]};}
	pii operator-(const pii&b)const{return(pii){(x-b.x+P[0])%P[0],(y-b.y+P[1])%P[1]};}
	pii operator*(const pii&b)const{return(pii){int(1LL*x*b.x%P[0]),int(1LL*y*b.y%P[1])};}
}h[2][N],pw[N],B;
pii get(int l,int r){
	int k1=lower_bound(a+1,a+1+m,l)-a-1,k2=upper_bound(a+1,a+1+m,r)-a-1;
	return h[l&1][k2]-h[l&1][k1]*pw[k2-k1];
}
int main(){
	srand(time(0));
	P[0]=998244853,P[1]=998244853+(rand()&0x7fff);
	B.x=3,B.y=rand()%10+3;
	pw[0]=(pii){1,1};
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*B;
	for(int i=1;i<=n;++i)if(s[i]=='0'){
		a[++m]=i;
		h[0][m]=h[0][m-1]*B+(pii){i%2+1,i%2+1};
		h[1][m]=h[1][m-1]*B+(pii){2-i%2,2-i%2};
	}
	int q;scanf("%d",&q);
	while(q--){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		puts(get(k1,k1+k3-1)==get(k2,k2+k3-1)?"Yes":"No");
	}
	return 0;
}