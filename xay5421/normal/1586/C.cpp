// author: xay5421
// created: Sun Oct 17 19:15:07 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,m;
int main(){
	rd(n),rd(m);
	vector<vector<int> >mp(n,vector<int>(m,0));
	rep(i,0,n-1)rep(j,0,m-1){
		int c;
		while(c=getchar(),c!='.'&&c!='X');
		mp[i][j]=c=='X';
	}
	vector<int>gg(m,0);
	rep(i,0,n-2){
		rep(j,0,m-2){
			if(mp[i][j+1]&&mp[i+1][j]){
				gg[j]=1;
			}
		}
	}
	per(i,m-2,0){
		gg[i]+=gg[i+1];
	}
	int Q;
	rd(Q);
	while(Q--){
		int l,r;
		rd(l),rd(r);
		--l,--r;
		if(l==r){
			puts("YES");
		}else{
			if(gg[l]-gg[r]>0){
				puts("NO");
			}else{
				puts("YES");
			}
		}
	}
	return 0;
}