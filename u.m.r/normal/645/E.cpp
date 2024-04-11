#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e6 + 10;
const int MM = 1e9 + 7;
char s[MAXN];
int lst[MAXN];
long long sum[MAXN];

int main(){
	int n,m,k;
	cin>>n>>k;
	scanf("%s", s+2);
	m = strlen(s+2);
	for(int i = 0; i <k ; i ++)
		lst[i] = 0;
	sum[0] = 0;sum[1] = 1;
	long long ans = 1;
	for(int i = 2; i <= m + 1; i++){
		int x = s[i]-'a';
		sum[i] = (sum[i-1] - sum[max(lst[x]-1, 0)]) % MM;
		lst[x] = i;
	//	ans = (ans + sum[i]) % MM;
		sum[i] += sum[i-1];
		sum[i] %= MM;
	//	cout<<sum[i]<<endl;
	}
//	for(int i = 0; i < k; i++)
//		cout<<lst[i]<<' '; cout<<endl;
	for(int j = 1; j <= n; j++){
	//	puts(")))");
		int p = 0;
		for(int l = 1; l < k; l++)
			if (lst[l] < lst[p])
				p = l;
		sum[m+1+j] = (sum[m+j] - sum[max(lst[p]-1, 0)]) % MM;
		lst[p] = j+m+1;
	//	ans = (ans + sum[m+1+j]) %MM;
		sum[m+1+j] += sum[m+j];
		sum[m+1+j] %= MM;
	}
	cout<<(sum[m+n+1]+MM)%MM<<endl;
	return 0;
}