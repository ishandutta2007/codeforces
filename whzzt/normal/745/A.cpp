#include"bits/stdc++.h"
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,r,l) for(int i=r;i>=l;i--)
#define mp make_pair
typedef long long ll;
using namespace std;
const int N=105;
char s[N*2];int n;
struct node {
	char s[N];int l;node(){memset(s,0,sizeof(s));l=0;}
	void add(char*x,int n){l=n;F(i,0,l-1)s[i]=x[i];}
} nd[N];
bool operator <(const node&a,const node&b){
	return strcmp(a.s,b.s)<0;
}
int main(){
	scanf("%s",s);n=strlen(s);
	F(i,n,2*n-1)s[i]=s[i-n];
	F(i,0,n-1)nd[i].add(s+i,n);
	sort(nd,nd+n);int ans=1;
	for(int i=1;i<n;i++)
		if(strcmp(nd[i].s,nd[i-1].s)!=0)
			ans++;
	cout<<ans<<endl;
	return 0;
}