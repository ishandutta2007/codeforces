#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long double a[9];
const char str[][8]={"x^y^z","x^z^y","(x^y)^z","y^x^z","y^z^x","(y^x)^z","z^x^y","z^y^x","(z^x)^y"};
int main(){
	long double x,y,z;
	scanf("%Lf%Lf%Lf",&x,&y,&z);
	a[0]=log(x)*pow(y,z),a[1]=log(x)*pow(z,y),a[2]=log(x)*y*z,
	a[3]=log(y)*pow(x,z),a[4]=log(y)*pow(z,x),a[5]=log(y)*x*z,
	a[6]=log(z)*pow(x,y),a[7]=log(z)*pow(y,x),a[8]=log(z)*x*y;
//	for(int i=0; i<9; ++i)
//		printf("%d: %Lf\n",i,a[i]);
	printf("%s\n",str[max_element(a,a+9)-a]);
	return 0;
}