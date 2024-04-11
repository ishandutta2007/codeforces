#include<bits/stdc++.h>
using namespace std;
int n;
int pos[300001];
int p[300001];
vector<int>vx,vy;
void sw(int x,int y){
	vx.push_back(pos[x]),vy.push_back(pos[y]);
	swap(pos[x],pos[y]);
	swap(p[pos[x]],p[pos[y]]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		pos[p[i]]=i;
	}
	for(int i=1; i<=n/2 ;i++){
		int cp=pos[i];
		if(pos[i]<=n/2){
			sw(p[cp],p[n]);
			sw(p[i],p[n]);
		}
		else{
			if(cp!=n){
				sw(p[cp],p[1]);
				sw(p[1],p[n]);
				sw(p[cp],p[1]);	
			}
			sw(p[n],p[i]);
		}
	}
	for(int i=n/2+1; i<=n ;i++){
		int cp=pos[i];
		if(pos[i]>n/2){
			if(i!=cp){
				sw(p[cp],p[1]);
				sw(p[i],p[1]);
				sw(p[cp],p[1]);
			}
			
		}
	}
	cout << vx.size() << endl;
	for(int i=0; i<vx.size() ;i++){
		cout << vx[i] << ' ' << vy[i] << '\n';
	}
}