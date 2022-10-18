#include<bits/stdc++.h>
#define N 250005
#define W 19

int T;

int n,a[N];

inline int cmn(int x,int y){
	return a[x]<a[y]?x:y;
}
inline int cmx(int x,int y){
	return a[x]>a[y]?x:y;
}
int lg[N],f[N][W],g[N][W];
inline void init(){
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		f[i][0]=g[i][0]=i;
	for(int j=1;j<W;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=cmn(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j]=cmx(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
}
inline int mn(int l,int r){
	int k=lg[r-l+1];
	return cmn(f[l][k],f[r-(1<<k)+1][k]);
}
inline int mx(int l,int r){
	int k=lg[r-l+1];
	return cmx(g[l][k],g[r-(1<<k)+1][k]);
}

std::stack<int> st;
int L[N],R[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		init();
		for(int i=1;i<=n;i++){
			while(st.size()&&a[i]<a[st.top()])
				L[st.top()]=i,st.pop();
			st.push(i);
		}
		while(st.size())
			L[st.top()]=n+1,st.pop();
		for(int i=1;i<=n;i++){
			while(st.size()&&a[i]>a[st.top()])
				R[st.top()]=i,st.pop();
			st.push(i);
		}
		while(st.size())
			R[st.top()]=n+1,st.pop();
		int x=1,res=0;
		while(x<n){
			if(L[x]<R[x])
				x=mn(x,R[x]-1);
			else
				x=mx(x,L[x]-1);
			res++;
		}
		printf("%d\n",res);
	}
}