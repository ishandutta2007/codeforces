#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
const long double eps = 1e-25;
int j,a,b,x,y,n;
long double min = 1e20,s;
void calc(int j,int i) {
	    if (j < 0) return;
		s =fabs(static_cast<long double>(j) / i - static_cast<long double>(x) / y);
        //if (j == 38236 && i == 49351) std::cout << min << ' ' << s << std::endl;
        //if (j == 34421 && i == 44427) std::cout << min << ' ' << s << std::endl;
        //printf("%d %d %lf\n",j,i,s);
        if (s < min - eps) {
			min =s;
			a = j; b = i;
		}
		else  if (fabs(s - min) <= eps && j < a) {
			a = j; b = i;
		}
}
int main() {
    //freopen("2.in","r",stdin); freopen("2.out","w",stdout);
	scanf("%d%d%d",&x,&y,&n);
	for (int i = 1; i <= n; ++i) {
		int j = static_cast<long long>(x) * i  / y;
		calc(j - 1,i); calc(j,i); calc(j + 1,i);
		/*for (int k = 0; k <= 500; ++k) 
			calc(j + k,i), calc(j - k,i);*/
	}
	printf("%d/%d",a,b);
}