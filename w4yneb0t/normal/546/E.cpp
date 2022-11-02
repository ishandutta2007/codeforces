#include<iostream>
#define f(i,n)for(int i=0;i++<n;)
#define M[201]
using namespace std;int*x,a M,h M,g M M,u M M,n,m,p,q,s,d=1;main(){cin>>n>>m;f(i,2*n)cin>>p,s+=a[i]=i<=n?g[i][i+n]=p:-p;f(i,m)cin>>p>>q,g[p][q+n]=g[q][p+n]=1;while(d--)f(i,2*n)if(a[i]>0){d=p=1;f(j,2*n)if(g[i][j]|g[j][i]&&h[i]>h[j])q=a[i],x=u[j]+i,i<j?u[i][j]+=q:q=q<*x?q:*x,*x-=q,p&=!q,a[i]-=q,a[j]+=q;if(s|(h[i]+=p)>2*n){cout<<"NO";return 0;}}cout<<"YES";f(i,n)f(j,n)cout<<'\n'<<u[i][j+n];}