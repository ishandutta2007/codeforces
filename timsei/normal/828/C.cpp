#pragma GCC optimize(4)
using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define F(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define ll long long
void rd(int &x) {
	char it=getchar();
	while(!isdigit(it)) it=getchar();x=0;
	while(isdigit(it)) {
		x*=10;x+=it-'0';it=getchar();
	}
}
char S[3000001];
int n;
char what[3000001];
bool vis[3000001];
int x,num;
int maxx;
int mx[3000001];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		scanf("%s",what);int l=strlen(what);
		rd(num);
		for(int j=1;j<=num;j++) {
			rd(x);
			maxx=max(maxx,x+l-1);
			if(mx[x]>=x+l-1) continue;
			mx[x]=x+l-1;
			S[x]=what[0];
//			for(int p=1;p<=7;p++) cout<<mx[p]<<" ";puts("");
			for(int k=x+1;k<=x+l-1;k++) {
				if(mx[k]>=x+l-1) {
					break;
				}
				else {
					if(!mx[k])S[k]=what[k-x];
//					cout<<k<<" "<<mx[k]<<" "<<S[k]<<endl;
					int kk=mx[k];
					mx[k]=x+l-1;
					if(kk) k=kk;
				}
			}
		}
	}
	for(int i=1;i<=maxx;i++) {
		if(!mx[i]) putchar('a');else putchar(S[i]);
	}
}