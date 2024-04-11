#include<bits/stdc++.h>
using namespace std;
int n,x,i,m,a[102000],b[102000],w=-1;
main(){
cin>>n>>x;
for(i=0; i<n; i++){
 cin>>m;
 if(a[m]>0)w=0;
 if(w!=0)if(a[m&x]>0 || b[m]>0)w=1;
 if(w!=0 && w!=1)if(b[m&x]>0)w=2;
 a[m]++;
 b[m&x]++;
}
if(w==0) cout<<0; else if(w==1) cout<<1; else if(w==2) cout<<2; else cout<<-1;
}//