#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 150005;
int n,k,num[N];

int calc1(vector<int> &a, vector<int> &b, int bit){
	if (!a.size()||!b.size()||bit==-1) return num[a.size()+b.size()];
	vector<int> c[2], d[2];
	for(int x:a) c[x>>bit&1].PB(x);
	for(int x:b) d[x>>bit&1].PB(x);
	return k>>bit&1 ? ((calc1(c[0],d[1],bit-1)+1ll)*(calc1(c[1],d[0],bit-1)+1)+P-1)%P : (calc1(c[0],d[0],bit-1)+calc1(c[1],d[1],bit-1)+1ll*num[c[0].size()]*num[c[1].size()]+1ll*num[d[0].size()]*num[d[1].size()])%P;
}

int calc(vector<int> &a, int bit){
	if (!a.size()||bit==-1) return num[a.size()];
	vector<int> c[2];
	for(int x:a) c[x>>bit&1].PB(x);
	return k>>bit&1 ? calc1(c[0],c[1],bit-1) : (calc(c[0],bit-1)+calc(c[1],bit-1))%P;
}

int main(){
	cin>>n>>k;
	vector<int> a(n);
	for(int &x:a)scanf("%d",&x);
	num[1] = 1;
	rep(i,2,n) num[i]=(num[i-1]*2+1)%P;
	cout<<calc(a,29)<<endl;
}