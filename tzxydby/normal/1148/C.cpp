#include <bits/stdc++.h>
using namespace std;
const int N=333000;
int n,i,j,m,e,d[N],p[N],a[5*N],b[5*N];
void s(int x,int y){
	if(x==y)return;
	a[m]=x,b[m]=y,m++;
	p[d[x]]=y,p[d[y]]=x;
	swap(d[x],d[y]);
}
int main(){
	for(cin>>n,i=1;i<=n;i++)cin>>d[i],p[d[i]]=i;
	for(i=1;i<=n;i++){
		e=n/2+i/2*(i%2?-1:1);
		j=p[e];
		if(j<=n/2){
			s(j,n);
			if(e>n/2)s(n,1),s(1,e);
			else if(n!=e)s(n,e);
		}
		else{
			s(j,1);
			if(e-1<n/2)s(n,1),s(n,e);
			else if(1!=e)s(1,e);
		}
	}
	for(cout<<m<<'\n',i=0;i<m;i++)cout<<a[i]<<" "<<b[i]<<'\n';
}