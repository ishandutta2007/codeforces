#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;

const int MLEN=100000;

typedef pair<long long,int> P;

map<long long,vector<long long> > divs;
vector<long long> xdivs;

vector<long long> ans;
int ln;

stack<P> st;

int main(){
	long long X;
	long long K;
	cin>>X>>K;
	for(long long i=1;i*i<=X;i++){
		if(X%i==0){
			xdivs.push_back(i);
			if(X/i!=i) xdivs.push_back(X/i);
		}
	}
	sort(xdivs.begin(),xdivs.end());
	for(int i=0;i<xdivs.size();i++){
		long long d=xdivs[i];
		vector<long long> tmp;
		for(int j=0;j<=i;j++){
			long long e=xdivs[j];
			if(d%e==0){
				tmp.push_back(e);
			}
		}
		divs[d]=tmp;
	}
	if(X==1){
		printf("1\n");
		return 0;
	}
	if(K>=MLEN){
		for(int i=0;i<MLEN;i++){
			printf("1%c",i==MLEN-1?'\n':' ');
		}
		return 0;
	}
	if(K==0){
		cout<<X<<"\n";
		return 0;
	}
	if(K==1){
		for(int i=0;i<xdivs.size();i++){
			cout<<xdivs[i]<<((i==xdivs.size()-1)?'\n':' ');
		}
		return 0;
	}
	for(int i=xdivs.size()-1;i>=0;i--) st.push(P(xdivs[i],K-1));
	ln=0;
	while(!st.empty()){
		P p=st.top();
		st.pop();
		long long x=p.first;
		int k=p.second;
		int ub=MLEN-ln;
		if(k==1){
			for(int i=0;i<min(ub,(int)divs[x].size());i++){
				ans.push_back(divs[x][i]);
				ln++;
			}
		}else if(x==1){
			ans.push_back(1);
			ln++;
		}else if(divs[x].size()==2){
			for(int i=0;i<min(ub,k);i++){
				ans.push_back(1);
				ln++;
			}
			if(ln<MLEN){
				ans.push_back(x);
				ln++;
			}
		}else{
			for(int i=divs[x].size()-1;i>=0;i--){
				st.push(P(divs[x][i],k-1));
			}
		}
		if(ln==MLEN) break;
	}
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<((i==ans.size()-1)?'\n':' ');
	return 0;
}