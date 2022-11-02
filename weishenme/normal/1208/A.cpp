#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int N=1000005;
vector<int > v[N];
int a[N],b[N],c[N],n,m,Q,x,y,opt;
char s[N];
int main(){
	scanf("%d",&Q);
	while (Q--){
		scanf("%d%d%d",&m,&x,&n);
		if (n%3==0)printf("%d\n",m);
		if (n%3==1)printf("%d\n",x);
		if (n%3==2)printf("%d\n",m^x);
	} 
}