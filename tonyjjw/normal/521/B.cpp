//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fi first
#define se second
#define mp make_pair
#define MN 100000
#define MOD 1000000009
using namespace std;

typedef pair<int,int> pii;
typedef __int64 ll;
ll po[MN];
pii A[MN];

int N;
map<pii,int> M;
set<int> S;

int num(pii A){
	int x,y,v=0;
	x=A.fi,y=A.se-1;
	if(M.find(mp(x-1,y))!=M.end())v++;
	if(M.find(mp(x,y))!=M.end())v++;
	if(M.find(mp(x+1,y))!=M.end())v++;
	return v;
}

void chk(int n){
	int x,y,f=1;
	x=A[n].fi,y=A[n].se+1;
	if(M.find(mp(x-1,y))!=M.end() && num(mp(x-1,y))==1)f=0;
	if(M.find(mp(x,y))!=M.end() && num(mp(x,y))==1)f=0;
	if(M.find(mp(x+1,y))!=M.end() && num(mp(x+1,y))==1)f=0;
	if(S.find(n)!=S.end() && f==0){
		S.erase(n);
	}
	if(f==1 && S.find(n)==S.end() && M.find(A[n])!=M.end()){
		S.insert(n);
	}
}

int getmin(){
	auto it=S.begin();
	return *it;
}

int getmax(){
	auto it=S.end();
	it--;
	return *it;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int x,y;
	for(int i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		A[i]=mp(x,y);
		M[A[i]]=i;
	}
	po[0]=1;
	for(int i=1;i<N;i++){
		po[i]=po[i-1]*N;
		po[i]%=MOD;
	}
	for(int i=0;i<N;i++){
		chk(i);
	}
	ll ans=0;
	for(int i=0;i<N;i++){
		int n;
		if(i&1)	n=getmin();
		else	n=getmax();
		ans+=po[N-1-i]*n;
		ans%=MOD;

		x=A[n].fi,y=A[n].se-1;
		M.erase(A[n]);
		S.erase(n);
		if(M.find(mp(x-1,y))!=M.end()){
			chk(M[mp(x-1,y)]);
		}
		if(M.find(mp(x,y))!=M.end()){
			chk(M[mp(x,y)]);
		}
		if(M.find(mp(x+1,y))!=M.end()){
			chk(M[mp(x+1,y)]);
		}
		y++;
		if(M.find(mp(x-2,y))!=M.end()){
			chk(M[mp(x-2,y)]);
		}
		if(M.find(mp(x-1,y))!=M.end()){
			chk(M[mp(x-1,y)]);
		}
		if(M.find(mp(x,y))!=M.end()){
			chk(M[mp(x,y)]);
		}
		if(M.find(mp(x+1,y))!=M.end()){
			chk(M[mp(x+1,y)]);
		}
		if(M.find(mp(x+2,y))!=M.end()){
			chk(M[mp(x+2,y)]);
		}
	}
	printf("%I64d",ans);
	return 0;
}
//*/