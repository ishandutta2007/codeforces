#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define FOR(it,st,en) for(int it=(st);it<(int)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
const int INF=(int)1e9; 
const double EPS=(LD)1e-7;

struct ST{
	void init(char c,string s){
		n=1;
		while(n<s.size())n<<=1;
		T.resize(2*n,0);
		B.resize(2*n,0);
		REP(i,s.size()){
			if(c==s[i])T[i+n]=1;
		}
		for(int i=n-1;i>0;i--){
			T[i]=T[2*i]+T[2*i+1];
		}
	}
	int get(int x,int y){return get(x,y,0,n,1);}
	int get(int x, int y, int xx, int yy, int l){
		// cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
		if(x<=xx && yy<=y){return T[l];}
		else if (yy<=x || xx>=y)return 0;
		if(l>=n)return 0;
		if(B[l]){
			B[2*l]=B[2*l+1]=true;
			B[l]=false;
			T[2*l]=min(T[l],(yy-xx)/2);
			T[2*l+1]=T[l]-T[2*l];
		}
		int t = xx + (yy-xx)/2;
		return get(x,y,xx,t,2*l) + get(x,y,t,yy,2*l+1);
	}
	void set(int x, int y){set(x,y,0,n,1);}
	void set(int x, int y,int xx, int yy, int l){
		if(x<=xx && yy<=y){T[l] = yy-xx;B[l]=true;return;}
		else if (yy<=x || xx>=y)return;
		if(l>=n)return;
		if(B[l]){
			B[2*l]=B[2*l+1]=true;
			B[l]=false;
			T[2*l]=min(T[l],(yy-xx)/2);
			T[2*l+1]=T[l]-T[2*l];
		}
		int t = xx + (yy-xx)/2;
		set(x,y,xx,t,2*l);
		set(x,y,t,yy,2*l+1);
		T[l]=T[2*l]+T[2*l+1];
	}
	void unset(int x, int y){unset(x,y,0,n,1);}
	void unset(int x, int y,int xx, int yy, int l){
		// cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
		if(yy==xx)return;
		if(x<=xx && yy<=y){T[l] = 0;B[l]=true;return;}
		else if (yy<=x || xx>=y)return;
		if(l>=n)return;
		if(B[l]){
			B[2*l]=B[2*l+1]=true;
			B[l]=false;
			T[2*l]=min(T[l],(yy-xx)/2);
			T[2*l+1]=T[l]-T[2*l];
		}
		int t = xx + (yy-xx)/2;
		unset(x,y,xx,t,2*l);
		unset(x,y,t,yy,2*l+1);
		T[l]=T[2*l]+T[2*l+1];
	}
	void expand(int xx, int yy, int l){
		if(l>=n)return;
		if(B[l]){
			B[2*l]=B[2*l+1]=true;
			B[l]=false;
			T[2*l]=min(T[l],(yy-xx)/2);
			T[2*l+1]=T[l]-T[2*l];
		}
		int t = xx + (yy-xx)/2;
		expand(xx,t,2*l);
		expand(t,yy,2*l+1);
	}

	int n;
	VI T;
	VI B;
};

void print(ST& s){
	int k=1;
	int i=1;
	while(k<2*s.n){
		REP(l,k){
			// REP(i,(2*s.n-k))cout<<" ";
			cout<<i<<":"<<s.T[i]<<" ";++i;
			// REP(i,2*s.n-k)cout<<" ";
		}
		cout<<endl;
		k<<=1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin>>n>>n>>s;
	ST seg[26];
	int arr[26];
	REP(i,26){
		seg[i].init(i+'a',s);
		arr[i]=0;
	}
	// print(seg[0]);
	// cout<<seg[0].get(7,10)<<endl;
	// seg[0].unset(0,s.size());
	if(true)REP(p,n){
		int i,j,k;
		cin>>i>>j>>k;
		i--;j--;
		// cout<<"["<<i<<","<<j+1<<")"<<endl;
		REP(l,26){
			arr[l]=seg[l].get(i,j+1);
			seg[l].unset(i,j+1);
		}
		REP(l,26){
			int t=l;
			if(!k)t=26-1-l;
			// if(t<5)cout<<char(t+'a')<<" = "<<arr[t]<<" "<<i<<endl;
			seg[t].set(i,i+arr[t]);
			// if(t<5)cout<<seg[t].get(0,3)<<endl;
			i+=arr[t];
			arr[t]=0;
		}

		// REP(i,26)seg[i].expand(0,seg[i].n,1);
		// REP(l,26){
		// 	REP(i,s.size())if(seg[l].T[seg[l].n+i])s[i]='a'+l;
		// }
		// cout<<s<<endl;

		// cout<<endl;
		assert(i==j+1);
	}
	REP(i,26)seg[i].expand(0,seg[i].n,1);
	REP(l,26){
		REP(i,s.size())if(seg[l].T[seg[l].n+i])s[i]='a'+l;
	}
	cout<<s<<endl;

	return 0;
}