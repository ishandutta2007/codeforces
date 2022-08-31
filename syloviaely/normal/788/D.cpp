#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
const int G=8000,N=1e8;
vector<int>A,B;
map<int,int>M;
int query(int x,int y){
	printf("%d %d %d\n",0,x,y);
	fflush(stdout);
	int k; scanf("%d",&k); return k;
}
int n,m;
int getran(){
	return (rand()<<15)+rand();
}
int getrand(){
	return abs(getran())%(N*2+1)-N;
}
void queryx(int x,int l,int r){
	if (l>=r-1) return;
	int mid=(l+r)/2;
	int w=query(x,mid);
	if (mid-w==l&&mid+w==r) return;
	if (mid-w==l){
		if (query(x,mid+w)==0) A.push_back(mid+w);
		return;
	}
	if (mid+w==r){
		if (query(x,mid-w)==0) A.push_back(mid-w);
		return;
	}
	if (query(x,mid-w)==0){
		A.push_back(mid-w); queryx(x,l,mid-w); queryx(x,mid-w,r);
	} else {
		A.push_back(mid+w); queryx(x,l,mid+w); queryx(x,mid+w,r);
	}
}
void queryy(int y,int l,int r){
	if (l>=r-1) return;
	int mid=(l+r)/2;
	int w=query(mid,y);
	if (mid-w==l&&mid+w==r) return;
	if (mid-w==l){
		if (query(mid+w,y)==0) B.push_back(mid+w);
		return;
	}
	if (mid+w==r){
		if (query(mid-w,y)==0) B.push_back(mid-w);
		return;
	}
	if (query(mid-w,y)==0){
		B.push_back(mid-w); queryy(y,l,mid-w); queryy(y,mid-w,r);
	} else {
		B.push_back(mid+w); queryy(y,l,mid+w); queryy(y,mid+w,r);
	}
}
void queryx(){
	int x,y,D;
	while (1){
		x=getrand(); y=getrand();
		D=query(x,y);
		if (D>G) break;
	}
	D--;
	int nowx=x,nowy=y;
	while (nowy!=N){
		int a=x,b=min(N,nowy+D),w=query(a,b);
		if (w<=D){
			if (b+w<=N&&M[b+w]==0&&query(a,b+w)==0) A.push_back(b+w),M[b+w]=1;
			if (b-w>=-N&&M[b-w]==0&&query(a,b-w)==0) A.push_back(b-w),M[b-w]=1;
		}
		nowy=b;
	}
	nowy=y;
	while (nowy!=-N){
		int a=x,b=max(-N,nowy-D),w=query(a,b);
		if (w<=D){
			if (b+w<=N&&M[b+w]==0&&query(a,b+w)==0) A.push_back(b+w),M[b+w]=1;
			if (b-w>=-N&&M[b-w]==0&&query(a,b-w)==0) A.push_back(b-w),M[b-w]=1;
		}
		nowy=b;
	}
	sort(A.begin(),A.end()); int p2=A.size();
	for (int i=1;i<p2;i++)
		if (A[i]-A[i-1]<=D*2) queryx(x,A[i-1],A[i]);
	nowx=x,nowy=y; M.clear();
	while (nowx!=N){
		int a=min(N,nowx+D),b=nowy,w=query(a,b);
		if (w<=D){
			if (a+w<=N&&M[a+w]==0&&query(a+w,b)==0) B.push_back(a+w),M[a+w]=1;
			if (a-w>=-N&&M[a-w]==0&&query(a-w,b)==0) B.push_back(a-w),M[a-w]=1;
		}
		nowx=a;
	}
	nowx=x;
	while (nowx!=-N){
		int a=max(-N,nowx-D),b=nowy,w=query(a,b);
		if (w<=D){
			if (a+w<=N&&M[a+w]==0&&query(a+w,b)==0) B.push_back(a+w),M[a+w]=1;
			if (a-w>=-N&&M[a-w]==0&&query(a-w,b)==0) B.push_back(a-w),M[a-w]=1;
		}
		nowx=a;
	}
	sort(B.begin(),B.end()); p2=B.size();
	for (int i=1;i<p2;i++)
		if (B[i]-B[i-1]<=D*2) queryy(y,B[i-1],B[i]);
	swap(A,B);
}
int main(){
	srand(time(0));
	queryx();
	cout<<1<<" "<<A.size()<<" "<<B.size()<<endl;
	for (int i=0;i<A.size();i++) printf("%d ",A[i]); printf("\n");
	for (int i=0;i<B.size();i++) printf("%d ",B[i]); printf("\n");
	fflush(stdout);
	return 0;
}