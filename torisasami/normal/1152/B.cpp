#include<iostream>
using namespace std;
int main() {
	int x, ans[44], t = 0,p[44],i,cx,flag,k;
	cin >> x;
	while (1) {
		cx = x;
		for (i = 0; i < 33; i++)
			p[i] = 0;
		flag = 0;
		for (i = 0; cx != 0; i++) {
			p[i] = cx % 2;
			cx /= 2;
			if (p[i] == 0)
				flag = 1;
		}
		if (flag == 0) {
			cout << t << endl;
			if(t%2==1)
			t++;
			for (i = 0; i < t/2; i++) {
				cout << ans[i];
				if (i != t/2 - 1)
					cout << " ";
				else
					cout << endl;
			}
			return 0;
		}
		else if (t % 2 == 0) {
			flag = 0;
			for (i = 30; i >= 0; i--) {
				if (p[i] == 1) {
					if (flag == 0)
						flag++;
					else if (flag == 2)
						p[i]--;
				}
				else {
					if (flag == 1) {
						flag++;
						ans[t/2] = i + 1;
						t++;
					}
					if (flag == 2)
						p[i] ++;
				}
			}
			k = 1;
			x = 0;
			for (i = 0; i < 30; i++) {
				if (p[i] == 1)
					x += k;
				k *= 2;
			}
		}
		else {
			x++;
			t++;
		}
	}
}