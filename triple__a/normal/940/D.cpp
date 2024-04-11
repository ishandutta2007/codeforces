#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

const int maxn=100007;
const int MAX_INT=1e9;
const int MIN_INT=-1e9;
int a[maxn];
char s[maxn];
int n,ubl,ubr,lbl,lbr;

int min(int r){
	int ans=MAX_INT;
	for (int i=0;i<=4;++i){
		ans=(ans<a[r-i]?ans:a[r-i]);
	} 
	return ans;
}

int max(int r){
	int ans=MIN_INT;
	for (int i=0;i<=4;++i){
		ans=(ans>a[r-i]?ans:a[r-i]);
	}
	return ans;
}

int ck(int r){
	int cur=0;
	for (int i=1;i<=4;++i){
		if (s[r-i]=='0') ++cur;
	}
	if (cur==4) return 0;
	if (cur==0) return 1;
	return 2;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	cin>>s;
	ubl=ubr=MAX_INT;
	lbl=lbr=MIN_INT; 
	for (int i=4;i<n;++i){
		int ck_t=ck(i);
		if (s[i]=='0'){
			if (ck_t==1){
				int mn=min(i)-1;
				ubr=(ubr<mn?ubr:mn);
			}
		}
		else{
			if (ck_t==0){
				int mx=max(i)+1;
				lbl=(lbl>mx?lbl:mx);
			}
		}
	}
	cout<<lbl<<" "<<ubr<<endl;
	return 0;
}