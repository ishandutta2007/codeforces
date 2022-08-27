#include <iostream>
#include <vector>

using namespace std;

int nextx(int x, int y, int m, int n){
	if((y==m)&&(x%2==1)) return (x+1);
	if((y==1)&&(x%2==0)) return(x+1);
	else return x;
}

int nexty(int x, int y, int m, int n){
	if((y==m)&&(x%2==1)) return (y);
	if((y==1)&&(x%2==0)) return(y);
	if(x%2==1) return (y+1);
	else return (y-1);
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n,p,k;
cin >> n >> k>> p;
int odd=0;
std::vector<int> a;
for(int i=0; i<n;i++){
	int c;
	cin >>c;
	if(c%2==1) odd++;
	a.push_back(c);
}

if(odd<(k-p)){
	cout << "NO";
	return 0;
}
if((odd-k+p)%2==1){
	cout << "NO";
	return 0;
}
if((odd-k+p)/2>(n-k)){
	cout << "NO";
	return 0;

}

cout << "YES" <<"\n";
std::vector<bool> u(n,false);
int parts=0;
int it=0;
int top=k-p;
if(p==0) top--;
while(parts<top){
	if(a[it]%2==1){
		cout << 1 << " " << a[it] << "\n";
		parts++;
		u[it]=true;
	}
	it++;
}
if(p==0){
	cout << (n-k+1);
	for(int i=0; i<n; i++) if(u[i]==false){
		cout<<" "<<a[i];
	}
}
parts=0;
it=0;
for(int i=0; i< (odd+p-n)-1; i++){
	cout<<2<<" ";
	while((a[it]%2==0)||u[it]==true) it++;
	cout<<a[it]<<" ";
	u[it]=true;
	while((a[it]%2==0)||u[it]==true) it++;
	cout<<a[it]<<"\n";
	u[it]=true;
	parts++;
}

it=0;
while(parts<(p-1)){
	if(a[it]%2==0){
		cout << 1 << " " << a[it] << "\n";
		parts++;
		u[it]=true;
	}
	it++;
}
if(p>parts){
	int c=0;
	for(int i=0; i<n; i++) if(u[i]==false) c++;
	cout << c;
	for(int i=0; i<n; i++) if(u[i]==false){
		cout<<" "<<a[i];
	}
}



//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}