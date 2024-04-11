#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n;
char ch[20] = "aeiou";
int main() {
	read(n);
	for(int i=5;i<=n;i++){
		if(n%i == 0 && n/i>=5){
			for(int j=0;j<n;j++){
				cout<<ch[((j/i)+j%i)%5];
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}