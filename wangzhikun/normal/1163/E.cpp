#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const int N = 200020;
int n,s[N],u[20],t[20];
void insert(int a){
	int st = a;
	for(int i=19;i>=0;i--){
		if((a>>i)&1)a^=u[i];
		if((a>>i)&1){
			u[i] = a;
			t[i] = st;
			return;
		}
	}
}
bool pos(int k){
	for(int i=0;i<20;i++)u[i] = t[i] = 0;
	for(int i=0;i<n;i++){
		if(s[i]>=(1<<k))continue;
		insert(s[i]);
	}
	for(int i=0;i<k;i++) if(!u[i])return 0;
	//for(int i=0;i<k;i++) cout<<u[i]<<' '<<t[i]<<endl;
	cout<<k<<endl;
	for(int i=0;i<(1<<k);i++){
		int cc = 0;
		for(int j=0;j<k;j++){
			if(((i>>j)&1)^((i>>(j+1))&1))cc^=t[j];
		}
		cout<<cc<<' ';
	}
	cout<<endl;
	return 1;
}
int main() {
	read(n);
	for(int i=0;i<n;i++) read(s[i]);
	for(int i=19;i>=0;i--) if(pos(i)) return 0;
	return 0;
}