#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

long long gcd(long long a,long long b){
	if(a<0) a*=-1;
	if(b<0) b*=-1;
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

struct frac{
	long long num,den;
	int id;
	frac(){}
	frac(long long a,long long b,int c){
		long long d=gcd(a,b);
		a/=d;b/=d;
		if(b<0){
			a*=-1,b*=-1;
		}
		id=c;
		num=a,den=b;
	}
	bool operator<(const frac &f){
		return num*f.den<f.num*den;
	}
};

int N;
long long xs[100100],ys[100100];

stack<frac> st;

int nxt[100100][18];

frac getFrac(int i,int j){
	long long dx=xs[j]-xs[i];
	long long dy=ys[j]-ys[i];
	return frac(dy,dx,j);
}

void print(frac f){
	cout<<"frac ";
	cout<<f.num/(double)f.den<<"\n";
}

void graham(){
	//N>=2;
	frac f=getFrac(N-2,N-1);
	nxt[N-1][0]=-1;
	nxt[N-2][0]=N-1;
	st.push(f);
	for(int i=N-3;i>=0;i--){
		frac cur=getFrac(i,i+1);
		while(!st.empty()&&cur<st.top()){
			int id=st.top().id;
			cur=getFrac(i,id);
			st.pop();
		}
		nxt[i][0]=cur.id;
		st.push(cur);
	}
}

int dep[100100];

void getTree(){
	dep[N-1]=0;
	for(int i=N-2;i>=0;i--){
		dep[i]=dep[nxt[i][0]]+1;
	}
	for(int j=1;j<18;j++){
		for(int i=0;i<N;i++){
			if(nxt[i][j-1]==-1) nxt[i][j]=-1;
			else nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		}
	}
}

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;i<18;i++){
		if((d>>i)&1){
			u=nxt[u][i];
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(nxt[u][i]!=nxt[v][i]) u=nxt[u][i],v=nxt[v][i];
	}
	return nxt[u][0];
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>xs[i]>>ys[i];
	}
	if(N==1){
		int Q;
		scanf("%d",&Q);
		for(int i=0;i<Q;i++){
			cout<<1<<"\n";
		}
		return 0;
	}
	graham();
	getTree();
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		int ans=lca(u,v);
		cout<<ans+1<<"\n";
	}
	return 0;
}