#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, z, i, max, min, a[222222], r,j,flag;
	cin >> n >> z;
	for (i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	max = n / 2;
	min = 0;
	while (max != min) {
		r = (max + min) / 2;
		flag = 1;
		for (i = 0; i < r; i++) {
			j = n-r+i;
			if (a[j] - a[i] < z)
				flag--;
		}
		if (flag == 1) {
			if (min+1 == max){
				r = max;
		flag = 1;
		for (i = 0; i < r; i++) {
			j = n-r+i;
			if (a[j] - a[i] < z)
				flag--;
		}
		if(flag==1)
		min++;
		else
		max--;
			}
			else
				min = r;
		}
		else {
			if (max-1 == min)
				max--;
			else
				max = r;
		}
	}
	cout << max << endl;
}