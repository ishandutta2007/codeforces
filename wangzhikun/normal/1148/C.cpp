#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,a[300010],br[300010],po[300010],opl[1500050],opr[1500050],opn = 0;

void miniop(int a,int b){
/*
	cout<<"miniOP"<<a<<' '<<b<<endl;
	if(abs(b-a)*2<n){
		cout<<"ERR"<<endl;
	}*/
	opl[opn] = a;
	opr[opn] = b;
	swap(br[a],br[b]);
	opn+=1;
}

void op(int a,int b){
	//cout<<"OP"<<a<<' '<<b<<endl;
	if(a>b)swap(a,b);
	if((b-a)*2>=n) miniop(a,b);
	else{
		if(b>n/2 && a<=n/2){
			miniop(a,n);
			miniop(b,1);
			miniop(1,n);
			miniop(a,n);
			miniop(b,1);
		}else{
			if(b>n/2 && a>n/2){
				miniop(1,b);
				miniop(1,a);
				miniop(1,b);
			}else{
				miniop(n,b);
				miniop(n,a);
				miniop(n,b);
			}
		}
	}
}

int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		br[i] = a[i];
		po[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		if(po[i]!=i){
			op(i,po[i]);
			po[a[i]] = po[i];
			swap(a[i],a[po[i]]);
			po[i] = i;
		}
	}
	cout<<opn<<endl;
	//if(opn>5*n)cout<<"ERR";
	for(int i=0;i<opn;i++){
		cout<<opl[i]<<' '<<opr[i]<<endl;
	}
	//for(int i=1;i<n;i++)if(br[i+1]!=br[i]+1)cout<<"ERR";
	return 0;
}