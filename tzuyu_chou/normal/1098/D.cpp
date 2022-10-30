#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
char op[500001];
ll val[500001];
int pos[500001];
ll cv[500001];
pair<ll,pair<int,int> >a[500001];
ll bit[500001];
void upd(int id,ll v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int in=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> op[i] >> val[i];
		a[i]={val[i],{(op[i]=='-'),i}};
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		int r=i;
		while(r<n && a[r+1].fi==a[i].fi && a[r+1].se.fi==0) r++;
		int r2=r;
		while(r2<n && a[r2+1].fi==a[i].fi) r2++;
		for(int j=i; j<=r ;j++) pos[a[j].se.se]=j;
		for(int j=r+1; j<=r2 ;j++) pos[a[j].se.se]=j-r+i-1;
		i=r2;
	}
	for(int i=1; i<=n ;i++){
		if(op[i]=='+'){
			upd(pos[i],val[i]);
			cv[pos[i]]=val[i];
			in++;
		}
		else{
			upd(pos[i],-val[i]);
			cv[pos[i]]=0;
			in--;
		}
		int ans=in;
		int cur=0;
		ll pf=0;
		if(in==0){
			cout << "0\n";
			continue;
		}
		while(cur<n){
			int newi=0;
			ll cpf=0;
			for(int j=18; j>=0 ;j--){
				if((newi|(1<<j))<=n && cpf+bit[newi|(1<<j)]<=pf*3){
					newi|=(1<<j);
					cpf+=bit[newi];
				}
			}
			newi++;
			cpf+=cv[newi];
			if(newi>n) break;
			if(cv[newi]>(cpf-cv[newi])*2) ans--;
			cur=newi;
			pf=cpf;
		}
		cout << ans << '\n';
	}
	
}