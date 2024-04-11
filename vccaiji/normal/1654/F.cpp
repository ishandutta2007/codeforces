#include<bits/stdc++.h>
using namespace std;
const int P1=998244853,P2=1000000007,B1=201203,B2=20020123;
struct hash_t {
	int x, y;
	hash_t(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	inline bool operator==(const hash_t &rhs)const{return x == rhs.x && y == rhs.y;}
	inline hash_t operator+(int v){return hash_t((1ll*x*B1+v)%P1,(1ll*y*B2+v)%P2);}
	inline hash_t operator+(const hash_t &rhs)const {return hash_t((x + rhs.x) % P1,(y + rhs.y) % P2);}
	inline hash_t operator-(const hash_t &rhs)const {return hash_t((x - rhs.x + P1) % P1, (y - rhs.y + P2) % P2); }
	inline hash_t operator*(const hash_t &rhs)const {return hash_t(1ll*x*rhs.x % P1,1ll*y*rhs.y % P2);}
}pw[20],val[20][1<<18];
int n;
char s[1<<19];
bool cmp(int i,int j){
	int now=0;
	for(int k=n-1;k>=0;k--){
		if(val[k][i^now]==val[k][j^now])now+=(1<<k);
	}
	return s[i^now]-'a'<s[j^now]-'a';
}
int main(){
	scanf("%d%s",&n,s);
	pw[0]=hash_t(B1,B2);
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*pw[i-1];
	for(int i=0;i<(1<<n);i++)val[0][i]=hash_t(s[i]-'a',s[i]-'a');
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++)val[i][j]=val[i-1][j]+pw[i-1]*val[i-1][j^(1<<(i-1))];
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)if(cmp(i,ans))ans=i;
	for(int i=0;i<(1<<n);i++)printf("%c",s[i^ans]);
	return 0;
}