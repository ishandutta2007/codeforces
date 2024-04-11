#include"bits/stdc++.h"
#define F(i,l,r) for(register int i=l;i<=r;i++)
#define mmap map<int,int>::iterator
#define mp make_pair
using namespace std;
typedef long long ll;
const int N=2005;
int n,m,a[N],val,d[N],last,ti;
int main(){
	scanf("%d%d",&n,&m);
	val=n/m;last=1;
	F(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]<=m) d[a[i]]++;
	}
	F(i,1,n){
		while(d[last] >= val)
			last ++ ;
		if(last>m) break;
		if(a[i]>m){
			a[i]=last;
			d[last] ++;
			ti ++;
		}
	}
	F(i,1,n){
		while(d[last] >= val)
			last ++ ;
		if (last>m) break;
		if (d[a[i]]>val){
			d[a[i]]--;
			a[i]=last;
			d[last]++;
			ti ++; 
		}
	}
	cout << val << ' ' << ti << endl;
	F(i,1,n) printf("%d ",a[i]);
	return 0;
}