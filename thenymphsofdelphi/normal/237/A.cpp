#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, mx = -1, t = 0, h, m, ht, mt;
    scanf("%d", &n);
    scanf("%d %d", &ht, &mt);
    while (--n){
    	scanf("%d %d", &h, &m);
    	if (ht == h && mt == m){
    		t++;
		}
		else{
			mx = max(mx, t);
			t = 0;
		}
		ht = h;
		mt = m;
	}
	mx = max(mx, t);
	cout << mx + 1;
}