/*
Contest: - 
Problem: Codeforces 258C 
Author: tzc_wk
Time: 2020.8.23
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
const int MOD=1e9+7;
int qpow(int x,int e){
	int ans=1;while(e){
		if(e&1) ans=ans*x%MOD;
		x=x*x%MOD;e>>=1;
	}
	return ans;
}
int n=read(),a[200005],cnt[200005],tmp[200005],num[200005];
vector<int> facs[200005];
int ans[200005];
signed main(){
	fz(i,1,n) a[i]=read();
	fz(i,1,n) cnt[a[i]]++;
	fz(i,1,200000) cnt[i]+=cnt[i-1];
	fz(i,1,200000){
		for(int j=1;j*j<=i;j++){
			if(i%j==0){
				facs[i].pb(j);
				if(i/j!=j) facs[i].pb(i/j);
			}
		}
		sort(facs[i].begin(),facs[i].end());
	}
	for(int i=1;i<=100000;i++){
		if(facs[i].size()>2) continue;
		if(cnt[i-1]) break;
		for(int j=1;j*i<=100000;j++){
			tmp[j]=cnt[j*i+i-1]-cnt[j*i-1];
		}
		for(int j=100000/i;j>=1;j--) tmp[j]+=tmp[j+1];	
		for(int j=1;j*i<=100000;j++){
			int mul=1;
			for(int k=facs[j].size()-1;k>=0;k--){
				int nxt;
				if(k==facs[j].size()-1) nxt=100001;
				else nxt=facs[j][k+1];
				if(k==facs[j].size()-1) mul=mul*(qpow(k+1,tmp[facs[j][k]])-qpow(k,tmp[facs[j][k]])+MOD)%MOD;
				else mul=mul*qpow(k+1,tmp[facs[j][k]]-tmp[nxt])%MOD;
			}
			ans[i]=(ans[i]+mul)%MOD;
//			cout<<i<<" "<<j<<" "<<mul<<endl;
		}
		for(int j=1;(j-1)*i<=100000;j++) tmp[j]=0;
	}
	int anss=0;
	fz(i,1,100000) foreach(it,facs[i]) if((*it)!=i) ans[*it]=(ans[*it]-ans[i]+MOD)%MOD;
	fz(i,1,100000) anss=(anss+ans[i])%MOD;
	cout<<anss<<endl;
	return 0;
}