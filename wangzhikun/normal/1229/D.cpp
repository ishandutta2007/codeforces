#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k,fac[10],nxt[120][120],cv[200][10],ocr[200] = {0},cho[200];

int main() {
	read(n);read(k);
	fac[0] = 1;
	for(int i=1;i<10;i++)fac[i] = fac[i-1]*i;
	int tim = 1;
	for(int i=0;i<fac[k];i++){
		int ci = i,nv[5] = {0,1,2,3,4};
	//	cout<<i<<" : "<<' ';
		for(int j=k-1;j>=0;j--){
			cv[i][j] = ci/fac[j];
			ci%=fac[j];
		}
		for(int j=0;j<k;j++){
			for(int m=0;m<j;m++){
				if(cv[i][m] >= cv[i][j])cv[i][m]++;
			}
		}
	//	for(int j=0;j<k;j++)cout<<cv[i][j]<<' ';
	//	cout<<endl;
	}
	for(int i=0;i<fac[k];i++){
		for(int j=0;j<fac[k];j++){
			nxt[i][j] = 0;
			int ccc[5];
			for(int l=0;l<k;l++){
				ccc[l] = cv[i][cv[j][l]];
			}
			for(int l=k-1;l>=0;l--){
				nxt[i][j]+=fac[l]*ccc[l];
				for(int m = 0;m<l;m++)if(ccc[m]>=ccc[l])ccc[m]--;
			}
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		int ccc[5],cans = 0;
		for(int j=0;j<k;j++){
			read(ccc[j]);
			ccc[j]--;
		}
		for(int l=k-1;l>=0;l--){
			cans+=fac[l]*ccc[l];
			for(int m = 0;m<l;m++)if(ccc[m]>=ccc[l])ccc[m]--;
		}ocr[cans] = i;
		ocr[fac[k]-1] = i;
		set0(cho);
		
		vector<int> ca;
		vector<int> co;
		for(register int ech=0;ech<fac[k];ech++)ca.push_back(ech);
		for(register int ech=0;ech<fac[k];ech++){
			int cmi = -1e9,cma = 1e9,cmx = -1,cp;
			for(int j=0;j<ca.size();j++){
				if(ocr[ca[j]]>cmi){
					cmi = ocr[ca[j]];
					cmx = ca[j];
					cp = j;
				}
				cma = min(cma,ocr[ca[j]]);
			}
			if(cma == cmi)break;
			swap(ca[cp],ca[ca.size()-1]);
			ca.pop_back();
			cho[cmx] = 1;
			co.push_back(cmx);
			for(auto ca:co){
				ocr[nxt[cmx][ca]] = max(ocr[nxt[cmx][ca]],cmi);
				ocr[nxt[ca][cmx]] = max(ocr[nxt[ca][cmx]],cmi);
			}
		}
		for(int j=0;j<fac[k];j++){
			ans+=ocr[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}