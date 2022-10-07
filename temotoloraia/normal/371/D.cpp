#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,a[200005],mas[200005];
int fix[200005];
int P (int k){
	if (fix[k]==k)return k;
	return fix[k]=P(fix[k]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		fix[i]=i;
	}
	cin>>m;
	while (m--){
		int p;
		cin>>p;
		if (p==1){
			int x,y;
			cin>>x>>y;
			int I=fix[x];
			while (I<=n){
				mas[I]+=y;
				if (mas[I]<a[I])break;
				y=mas[I]-a[I];
				mas[I]=a[I];
				if (I==n)break;
				fix[I]=fix[I+1];
				I=P(I);
			}
		}
		else {
			int x;
			cin>>x;
			cout<<mas[x]<<endl;
		}
	}
    return 0;
}