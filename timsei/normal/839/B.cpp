#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
const int K = 1001;

int a[K] , n , m ,  cnt , flag , k;
int two , four;
int main() {
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= k;i ++) scanf("%d",&a[i]);
    two = n * 2;
    four = n;
    for(int i = 1;i <= k;i ++) {
        int p = (a[i] / 4);
        if(a[i] % 4 != 3 ) {
            if(four < p) {
                p -= four;
                four = 0;
                p = p * 4 + a[i] % 4; 
                while(p > 1) {
                    p -= 2;
                    two --;
                }
                a[i] = p;
            }
            else {
                four -= p;
                a[i] -= p * 4;
                if(a[i] == 2) {
                    two--;
                    a[i] = 0;
                }
            }
        }
        else {
            if(four < p) {
                p -= four;
                four = 0;
                p = p * 4 + 3;
                while(p > 1) {
                    p -= 2;
                    two --;
                }
                a[i] = p;
            }
            else {
                four -= p;
                a[i] -= p * 4;
                if(four > 0) {
                    four --;
                    a[i] = 0;
                }
                else {
                	two --;
                	a[i] = 1;
				}
            }            
        }
    }
    int hh = 0;
    if(four) {
    	for(int i = 1;i <= four ;i ++) {
    		two ++; hh ++;
		}
	}
	if(four , 0) while(1);
    for(int i = 1;i <= k;i ++) {
    	if(a[i]) {
    		if(hh) hh --;
    		else two --;
		}
	}
	//  .. 
	while(hh > 1) {
		hh -=2;
		two ++;
	}
	if(two <0) puts("NO");else
	puts("YES");
}