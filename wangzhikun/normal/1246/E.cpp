#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

bitset<2020> D[65536];
int n,k,a[16];
int csu = 0;
priority_queue<pii> Q;
int main() {
	read(n);read(k);
	D[0][0] = 1;
	for(int i=0;i<n;i++){
		read(a[i]);
		csu+=a[i];
	}
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++) if(i&(1<<j)) D[i] |= D[i^(1<<j)]<<(a[j]);
		for(int j=(csu/k)*k+k;j>0;j-=k){
			if(D[i][j]){
				D[i][j/k] = 1;
			}
		}
		
	}
	if(!D[(1<<n)-1][1]){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	int x = (1<<n)-1,d = 0,v = 1;
	while(x){
		//cout<<x<<endl;
		while(v*k<=csu && D[x][v*k]){
			v*=k;
			d++;
		}
		//cout<<x<<endl;
		for(int i=0;i<n;i++){
			if(x&(1<<i) && v>=a[i] && D[x^(1<<i)][v-a[i]]){
				x^=(1<<i);
				v-=a[i];
				Q.push(make_pair(d,a[i]));
				goto nxt;
			}
		}
		nxt:;
	}
	while(Q.size()>1){
		pii a = Q.top();Q.pop();
		pii b = Q.top();Q.pop();
		cout<<a.second<<' '<<b.second<<endl;
		int cv = a.second+b.second,cd = a.first;
		while(cv%k == 0){
			cv/=k;
			cd--;
		}
		Q.push(make_pair(cd,cv));
	}
	return 0;
}