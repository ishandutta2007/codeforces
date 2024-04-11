#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1005;
char s[N];
int s1[N],s2[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n) s1[i]=s1[i-1]+(s[i]=='(');
	Rep(i,n,1) s2[i]=s2[i+1]+(s[i]==')');
	For(i,0,n) if (s1[i]==s2[i+1]){
		if(!s1[i]) puts("0");
		else{
			printf("1\n%d\n",2*s1[i]);
			For(j,1,i) if (s[j]=='(') printf("%d ",j);
			For(j,i+1,n) if (s[j]==')') printf("%d ",j);
		}
		exit(0);
	}
}