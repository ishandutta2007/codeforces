#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int fir=0,sec=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>fir)
				sec=fir,fir=a[i];
			else if(a[i]>sec)
				sec=a[i];
		}
		printf("%d\n",fir+sec);
	}
	return 0;
}