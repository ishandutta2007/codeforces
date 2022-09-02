#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int P;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int oldu,oldv;
map<int,int>mp1,mp2;
void oh(int u,int v){
	vector<int>st;
	while(1){
		if(mp1[u]==-1)break;
		st.push_back(mp1[u]);
		switch(mp1[u]){
			case 1:
				u=su(u,1);
				break;
			case 2:
				u=ad(u,1);
				break;
			case 3:
				u=po(u,P-2);
				break;
		}
	}
	reverse(st.begin(),st.end());
	while(1){
		if(mp2[v]==-1)break;
		st.pb(mp2[v]<=2?3-mp2[v]:3);
		switch(mp2[v]){
			case 1:
				v=su(v,1);
				break;
			case 2:
				v=ad(v,1);
				break;
			case 3:
				v=po(v,P-2);
				break;
		}
	}
	printf("%d\n",SZ(st));
	for(auto&x:st)printf("%d ",x);
	for(auto&x:st){
		if(x==1)uad(oldu,1);
		else if(x==2)usu(oldu,1);
		else oldu=po(oldu,P-2);
	}
	assert(oldu==oldv);
	exit(0);
}
queue<int>qu,qv;
void ex1(int u){
	//D("u=%d\n",u);
	auto ps=[&](int u_,int opt){
		if(!mp1.count(u_)){
			mp1[u_]=opt;
			qu.push(u_);
			if(mp2.count(u_)){
				oh(u_,u_);
			}
		}
	};
	ps(ad(u,1),1);
	ps(su(u,1),2);
	if(u){
		ps(po(u,P-2),3);
	}
}
void ex2(int v){
	//D("v=%d\n",v);
	auto ps=[&](int v_,int opt){
		if(!mp2.count(v_)){
			mp2[v_]=opt;
			qv.push(v_);
			if(mp1.count(v_)){
				oh(v_,v_);
			}
		}
	};
	ps(ad(v,1),1);
	ps(su(v,1),2);
	if(v){
		ps(po(v,P-2),3);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int u,v;
	scanf("%d%d%d",&u,&v,&P);
	oldu=u,oldv=v;
	mp1[u]=-1,mp2[v]=-1;
	qu.push(u);
	qv.push(v);
	while(1){
		ex1(qu.front());
		qu.pop();
		ex2(qv.front());
		qv.pop();
	}
	return 0;
}