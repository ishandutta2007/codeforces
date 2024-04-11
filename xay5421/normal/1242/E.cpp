// author: xay5421
// created: Sun Dec 20 08:39:34 2020
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=300005;
int n;
array<int,2>a[N];
vector<int>v[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i][0]),a[i][1]=i;
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	deque<int>q;
	int ind=0;
	rep(i,1,a[1][0]){
		q.push_back(++ind);
		v[a[1][1]].push_back(ind);
	}
	rep(i,2,n){
		int w=min(a[i][0]-1,(SZ(q)+a[i][0]-(i==n?3:a[i+1][0]))/2);
		rep(j,1,w-1){
			v[a[i][1]].push_back(q.back());
			q.pop_back();
		}
		v[a[i][1]].push_back(q.back());
		rep(j,w+1,a[i][0]-1){
			v[a[i][1]].push_back(++ind);
			q.push_back(ind);
		}
		v[a[i][1]].push_back(q.front());
		q.push_back(q.front());
		q.pop_front();
	}
	printf("%d\n",ind);
	rep(i,1,n){
		for(auto x:v[i])printf("%d ",x);
		puts("");
	}
	return 0;
}