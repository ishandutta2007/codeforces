#include <queue>
#include <cmath>
#include <bitset>
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
const int MAX = 7070;
int n,q,op;
bitset<MAX> al[100010],divs[MAX],muls[MAX],sqrfree;
int main() {

	for(int i=1;i<=7000;i++){
		sqrfree[i] = 1;
		for(int j=2;j*j<=i;j++){
			if(i%(j*j) == 0)sqrfree[i] = 0;
		}
	//	cout<<i<<' '<<sqrfree[i]<<endl;
	}
	for(int i=1;i<=7000;i++){
		for(int j=1;j<=i;j++){
			if(i%j == 0){
				divs[i].set(j);
				if(sqrfree[i/j])muls[j].set(i);
			}
		}
	}
	read(n);read(q);
	while(q--){
		read(op);
		if(op == 1){
			int x,v;
			read(x);read(v);
			al[x] = divs[v];
		}
		if(op == 2){
			int x,y,z;
			read(x);read(y);read(z);
			al[x] = al[y]^al[z];
		}
		if(op == 3){
			int x,y,z;
			read(x);read(y);read(z);
			al[x] = al[y]&al[z];
		}
		if(op == 4){
			int x,v;
			read(x);read(v);
			//for(int i=1;i<=10;i++)cout<<al[x][i];
			//cout<<endl;
			cout<<(al[x]&muls[v]).count()%2;
		}
	}
	return 0;
}