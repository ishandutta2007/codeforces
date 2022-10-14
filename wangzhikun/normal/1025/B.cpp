//  Created by  on 2018/8/19.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,a[200010],b[200010],fnd = 0,isnp[1000010] = {0};
void test(ll num){
	if(fnd)return;
	for(ll i=0;i<n;i++){
		if(a[i]%num!=0 && b[i]%num!=0)return;
	}
	fnd = 1;
	cout<<num<<endl;
}
int main() {
	for(ll i=2;i<1000000;i++){
		if(!isnp[i]){
			for(ll j = i+i;j<1000000;j+=i)isnp[j] = 1;
		}
	}
	read(n);
	for(ll i=0;i<n;i++){
		read(a[i]);read(b[i]);
	}
	ll fnd1 = 0,fnd2 = 0,ao = a[0],bo = b[0];
	for(ll i=2;i*i<=ao;i++){
		if(!isnp[i] && ao%i == 0){
			fnd1 = 1;
			test(i);
			while(ao%i == 0)ao/=i;
		}
	}
	if(ao>1)test(ao);
	for(ll i=2;i*i<=bo;i++){
		if(!isnp[i] && bo%i == 0){
			fnd2 = 1;
			test(i);
			while(bo%i == 0)bo/=i;
		}
	}
	if(bo>1)test(bo);
	if(!fnd){
		cout<<-1<<endl;
	}
	return 0;
}