#include<bits/stdc++.h>
using namespace std;
#define I int
#define K map<I,I>
const I N=1000005;K M,C;I L[N],R[N],n,S[N],c,d[N];
#define F(x) for(I i=1;i<=x;i++)
main(){cin>>n;F(n)cin>>L[i]>>R[i],M[L[i]]=M[R[i]]=M[L[i]+1]=M[R[i]+1]=1;for(K::iterator t=M.begin();t!=M.end();t++)C[t->first]=++c;F(n)L[i]=C[L[i]],R[i]=C[R[i]],S[L[i]]++,S[R[i]+1]--;F(c)S[i]+=S[i-1],d[i]=d[i-1]+(S[i]<2);F(n)if(!(d[R[i]]-d[L[i]-1]))return cout<<i,0;puts("-1");}