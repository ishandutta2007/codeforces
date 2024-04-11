# include <bits/stdc++.h>
using namespace std;

set < long long > st;
long long n, sq;

int main()
{
	cin >> n;
	sq = sqrt(n);
	for (int i = 1; i <= sq; i++){
		if(n % i == 0){
			long long p1 = n / i;
			long long p2 = i;
			
			st.insert((p1 * (p1 - 1)) / 2 * i + p1);
			
			st.insert((p2 * (p2 - 1)) / 2 * (n / i) + p2);
		}
	}
	for (auto c:st){
		cout << c << ' ';
	}
}